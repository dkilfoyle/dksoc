`default_nettype none
`include "clockworks.v"

module Memory (
   input              clk,
   input      [31:0]  mem_addr,  // address to be read
   output reg [31:0]  mem_rdata, // data read from memory
   input   	          mem_rstrb  // goes high when processor wants to read
);

   reg [31:0] MEM [0:255]; 

`ifdef BENCH
   localparam slow_bit=13;
`else
   localparam slow_bit=19;
`endif

`include "riscv_assembly.v"
   integer L0_   = 8;
   integer wait_ = 32;
   integer L1_   = 40;
   
   initial begin
      LI(s0,0);   
      LI(s1,16);
   Label(L0_); 
      LB(a0,s0,400); // LEDs are plugged on a0 (=x10)
      CALL(LabelRef(wait_));
      ADDI(s0,s0,1); 
      BNE(s0,s1, LabelRef(L0_));
      EBREAK();
      
   Label(wait_);
      LI(t0,1);
      SLLI(t0,t0,slow_bit);
   Label(L1_);
      ADDI(t0,t0,-1);
      BNEZ(t0,LabelRef(L1_));
      RET();

      endASM();

      // Note: index 100 (word address)
      //     corresponds to 
      // address 400 (byte address)
      MEM[100] = {8'h4, 8'h3, 8'h2, 8'h1};
      MEM[101] = {8'h8, 8'h7, 8'h6, 8'h5};
      MEM[102] = {8'hc, 8'hb, 8'ha, 8'h9};
      MEM[103] = {8'hff, 8'hf, 8'he, 8'hd};  
   end

   always @(posedge clk) begin
      if(mem_rstrb) begin
         mem_rdata <= MEM[mem_addr[31:2]];
      end
   end
endmodule

module Processor (
    input 	          clk,
    input 	          resetn,
    output     [31:0] mem_addr, 
    input      [31:0] mem_rdata, 
    output 	          mem_rstrb,
    output reg [31:0] x10 =0		  
);

  reg [31:0] PC=0;
  reg [31:0] instr;

  // decoder
  // R-type  [31  funct7     25]  [24  rs2  20]  [19  rs1  15]  [14  funct3  12]  [11  rd        7]  [6  opcode  0]
  // S-type  [31  imm[11:5]  25]  [24  rs2  20]  [19  rs1  15]  [14  funct3  12]  [11  imm[4:0]  7]  [6  opcode  0]
  // I-type  [31  imm[11:0]                 20]  [19  rs1  15]  [14  funct3  12]  [11  rd        7]  [6  opcode  0]
  // U-type  [31  imm[31:12]                                                 12]  [11  rd        7]  [6  opcode  0]

  // decode op codes
  wire isALUreg  =  (instr[6:0] == 7'b0110011); // rd <- rs1 OP rs2   
  wire isALUimm  =  (instr[6:0] == 7'b0010011); // rd <- rs1 OP Iimm
  wire isBranch  =  (instr[6:0] == 7'b1100011); // if(rs1 OP rs2) PC<-PC+Bimm
  wire isJALR    =  (instr[6:0] == 7'b1100111); // rd <- PC+4; PC<-rs1+Iimm
  wire isJAL     =  (instr[6:0] == 7'b1101111); // rd <- PC+4; PC<-PC+Jimm
  wire isAUIPC   =  (instr[6:0] == 7'b0010111); // rd <- PC + Uimm
  wire isLUI     =  (instr[6:0] == 7'b0110111); // rd <- Uimm   
  wire isLoad    =  (instr[6:0] == 7'b0000011); // rd <- mem[rs1+Iimm]
  wire isStore   =  (instr[6:0] == 7'b0100011); // mem[rs1+Simm] <- rs2
  wire isSYSTEM  =  (instr[6:0] == 7'b1110011); // special

  // decode source and destination registers
  wire [4:0] rs2Id = instr[24:20];
  wire [4:0] rs1Id = instr[19:15];
  wire [4:0] rdId  = instr[11:7];

  // extract funct7 and funct3
  wire [6:0] funct7 = instr[31:25];
  wire [2:0] funct3 = instr[14:12];

  // build immediates for each instruction type
  wire [31:0] Uimm={    instr[31],   instr[30:12], {12{1'b0}}};
  wire [31:0] Iimm={{21{instr[31]}}, instr[30:20]};
  wire [31:0] Simm={{21{instr[31]}}, instr[30:25], instr[11:7]};
  wire [31:0] Bimm={{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
  wire [31:0] Jimm={{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};

  // register bank
  reg [31:0] RegisterBank [0:31];
  reg [31:0] rs1;
  reg [31:0] rs2;
  wire [31:0] writeBackData;
  wire writeBackEn;

  `ifdef BENCH   
    integer     i;
    initial begin
      for(i=0; i<32; ++i) begin
    RegisterBank[i] = 0;
      end
    end
  `endif   

  // ALU
  wire [31:0] aluIn1 = rs1;
  wire [31:0] aluIn2 = isALUreg | isBranch ? rs2 : Iimm;
  reg [31:0] aluOut;
  wire [4:0] shamt = isALUreg ? rs2[4:0] : instr[24:20]; // shift amount

  wire [31:0] aluPlus = aluIn1 + aluIn2;
  wire [32:0] aluMinus = {1'b1, ~aluIn2} + {1'b0, aluIn1} + 33'b1; // A-B = A + ~B + 1
  wire EQ = (aluMinus[31:0] == 0); // A==B if A-B = 0
  wire LTU = aluMinus[32]; // because aluMinus is sign extended, MSB 1 for negative
  wire LT = (aluIn1[31] ^ aluIn2[31]) ? aluIn1[31] : aluMinus[32]; // if signs differ then A < B if A is negative, else check if A-B is negative

  // Flip a 32 bit word. Used by the shifter (a single shifter for
  // left and right shifts, saves silicium !)
  function [31:0] flip32;
    input [31:0] x;
    flip32 = {x[ 0], x[ 1], x[ 2], x[ 3], x[ 4], x[ 5], x[ 6], x[ 7], 
		x[ 8], x[ 9], x[10], x[11], x[12], x[13], x[14], x[15], 
		x[16], x[17], x[18], x[19], x[20], x[21], x[22], x[23],
		x[24], x[25], x[26], x[27], x[28], x[29], x[30], x[31]};
  endfunction

  wire [31:0] shifter = $signed({instr[30] & aluIn1[31], shifter_in}) >>> aluIn2[4:0];
  wire [31:0] shifter_in = (funct3 == 3'b001) ? flip32(aluIn1) : aluIn1;
  wire [31:0] leftshift = flip32(shifter);

  // ADD/SUB/ADDI: funct7[5] 0=ADD, 1=SUB, instr[5]=I
  // SRL/SRLI/SRA/SRAI: funct7[5] 0=logical, 1=arthimetic
  always @(*) begin
    case (funct3)
      3'b000: aluOut = (funct7[5] & instr[5]) ? aluMinus[31:0] : aluPlus; // ADD/ADDI/SUB/SUBI
      3'b001: aluOut = leftshift;                                         // SLL
      3'b010: aluOut = {31'b0, LT};                                       // SLT
      3'b011: aluOut = {31'b0, LTU};                                      // SLTU
      3'b100: aluOut = (aluIn1 ^ aluIn2);                                 // XOR
      3'b101: aluOut = shifter;                                           // SRA/SRAI
      3'b110: aluOut = (aluIn1 | aluIn2);                                 // OR
      3'b111: aluOut = (aluIn1 & aluIn2);                                 // AND
    endcase
  end

  // The predicate for branch instructions
  reg takeBranch;
  always @(*) begin
    case(funct3)
      3'b000: takeBranch = EQ;
      3'b001: takeBranch = !EQ;
      3'b100: takeBranch = LT;
      3'b101: takeBranch = !LT;
      3'b110: takeBranch = LTU;
      3'b111: takeBranch = !LTU;
      default: takeBranch = 1'b0;
    endcase
  end

  wire [31:0] PCplusImm = PC + (instr[3] ? Jimm[31:0] :
                                instr[4] ? Uimm[31:0] :
                                Bimm);
  wire [31:0] PCplus4 = PC + 4;

  assign writeBackData = (isJAL || isJALR) ? (PCplus4) :
                         (isLUI) ? Uimm :
                         (isAUIPC) ? (PCplusImm) :
                         aluOut;
  assign writeBackEn = (state==EXECUTE && !isBranch); // save writeBackData to RegisterFile[rdId]
                         
  wire [31:0] nextPC = (isBranch && takeBranch || isJAL) ? PCplusImm :
                        isJALR ? {aluPlus[31:1], 1'b0} :
                        PCplus4;


  wire [31:0] loadstore_addr = rs1 + Iimm;
  wire [15:0] LOAD_halfword = loadstore_addr[1] ? mem_rdata[31:16] : mem_rdata[15:0];
  wire [15:0] LOAD_byte = loadstore_addr[0] ? LOAD_halfword[15:8] : LOAD_halfword[7:0];
  wire mem_byteAccess = funct3[1:0] == 2'b00;
  wire mem_halfwordAcc = funct3[1:0] == 2'b01;
  wire LOAD_sign = !funct3[2] & (mem_byteAccess ? LOAD_byte[7] : LOAD_halfword[15]); // sign is MSB, or 0 if unsigned load (funct3==0)
  wire [31:0] LOAD_data = mem_byteAccess ? {{24{LOAD_sign}}, LOAD_byte} : mem_halfwordAcc ? {{16{LOAD_sign}}, LOAD_halfword} : mem_rdata;

  // states
  // The state machine
  localparam FETCH_INSTR = 0;
  localparam WAIT_INSTR  = 1;
  localparam FETCH_REGS  = 2;
  localparam EXECUTE     = 3;
  localparam LOAD        = 4;
  localparam WAIT_DATA   = 5;
  reg [2:0] state = FETCH_INSTR;

  // cycle
  always @(posedge clk) begin
    if (!resetn) begin
      PC <= 0;
      state <= FETCH_INSTR;
    end else begin
      if (writeBackEn && rdId != 0) begin
        RegisterBank[rdId] <= writeBackData;
        if(rdId == 10) x10 <= writeBackData;
        `ifdef BENCH	 
	        // $display("x%0d <= %b", rdId, writeBackData);
        `endif
      end;

      case (state)
        FETCH_INSTR: begin
          state <= WAIT_INSTR;
        end
        WAIT_INSTR: begin
          instr <= mem_rdata;
          state <= FETCH_REGS;
        end
        FETCH_REGS: begin
          rs1 <= RegisterBank[rs1Id];
          rs2 <= RegisterBank[rs2Id];
          state <= EXECUTE;
        end
        EXECUTE: begin
          if (!isSYSTEM) begin
            PC <= nextPC;
          end
          state <= isLoad ? LOAD : FETCH_INSTR;
          `ifdef BENCH
            if(isSYSTEM) $finish();
          `endif
        end
        LOAD: begin
          state <= WAIT_DATA;
        end
        WAIT_DATA: begin
          state <= FETCH_INSTR;
        end
      endcase 
    end
  end

  assign mem_addr = (state == WAIT_INSTR || state == FETCH_INSTR) ? PC : loadstore_addr;
  assign mem_rstrb = (state == FETCH_INSTR || state == LOAD);

  `ifdef BENCH2
    always @(posedge clk) begin
      if (state == FETCH_REGS) begin
        case (1'b1)
          isALUreg: $display("ALUreg rd=%d rs1=%d rs2=%d funct3=%b", rdId, rs1Id, rs2Id, funct3);
          isALUimm: $display("ALUimm rd=%d rs1=%d imm=%0d funct3=%b", rdId, rs1Id, Iimm, funct3);
          isBranch: $display("BRANCH");
          isJAL:    $display("JAL");
          isJALR:   $display("JALR");
          isAUIPC:  $display("AUIPC");
          isLUI:    $display("LUI");	
          isLoad:   $display("LOAD");
          isStore:  $display("STORE");
          isSYSTEM: $display("SYSTEM");
        endcase
        if (isSYSTEM) $finish();
      end
    end
  `endif

  // outputs
  assign mem_addr = PC;
  assign mem_rstrb = (state == FETCH_INSTR);

endmodule

module SOC (
  input CLK,
  input RESET,
  output [4:0] LEDS,
  input RXD,
  output TXD
);

  wire clk;
  wire resetn;

  Memory RAM(
    .clk(clk),
    .mem_addr(mem_addr),   //input
    .mem_rstrb(mem_rstrb), //input
    .mem_rdata(mem_rdata)  //output
  );

  wire [31:0] mem_addr;
  wire [31:0] mem_rdata;
  wire mem_rstrb;
  wire [31:0] x10;

  Processor CPU(
    .clk(clk),
    .resetn(resetn),
    .mem_rdata(mem_rdata), //input
    .mem_addr(mem_addr),   //output
    .mem_rstrb(mem_rstrb), //output
    .x10(x10)
  );

  assign LEDS = x10[4:0];

   // Gearbox and reset circuitry.
   Clockworks
    // #(.SLOW(21)) // Divide clock frequency by 2^21
   CW(
     .CLK(CLK),
     .RESET(RESET),
     .clk(clk),
     .resetn(resetn)
   );
   
   assign TXD  = 1'b0; // not used for now
endmodule
# Set RISCV CPU architecture
ARCH=rv32i
ABI=ilp32
OPTIMIZE=-Os

# Configure RV toolchain
RVTOOLCHAIN_DIR=/opt/riscv
RVTOOLCHAIN_BIN_DIR=$(RVTOOLCHAIN_DIR)/bin
RVTOOLCHAIN_LIB_DIR=$(RVTOOLCHAIN_DIR)/lib
RVTOOLCHAIN_GCC_LIB_DIR=$(RVTOOLCHAIN_DIR)/lib/gcc/riscv32-unknown-elf/11.1.0
RVTOOLCHAIN_BIN_PREFIX=riscv32-unknown-elf
RVAS=$(RVTOOLCHAIN_BIN_DIR)/$(RVTOOLCHAIN_BIN_PREFIX)-as
RVLD=$(RVTOOLCHAIN_BIN_DIR)/$(RVTOOLCHAIN_BIN_PREFIX)-ld
RVOBJCOPY=$(RVTOOLCHAIN_BIN_DIR)/$(RVTOOLCHAIN_BIN_PREFIX)-objcopy
RVOBJDUMP=$(RVTOOLCHAIN_BIN_DIR)/$(RVTOOLCHAIN_BIN_PREFIX)-objdump
RVGCC=$(RVTOOLCHAIN_BIN_DIR)/$(RVTOOLCHAIN_BIN_PREFIX)-gcc

# Compilation rules
.c.o: $<
	$(RVGCC) $(RVCFLAGS) $(RVUSERCFLAGS) -c $<

.S.o: $< $(RV_BINARIES)
	$(RVAS) $(RVASFLAGS) $(RVUSERASFLAGS) $< -o $@ 

# compile / assemble flags
RVASFLAGS=-march=$(ARCH) -mabi=$(ABI) 
RVCFLAGS=-Os -fno-pic -march=$(ARCH) -mabi=$(ABI) -fno-stack-protector -w -Wl,--no-relax 
RAM_SIZE=6144
LIBOBJECTS=putchar.o wait.o print.o memcpy.o errno.o

# Final Targets

%.bram.elf: %.o start.o $(LIBOBJECTS)
	$(RVLD) -T bram.ld -m elf32lriscv -nostdlib -no-relax $< $(LIBOBJECTS) $(RVTOOLCHAIN_GCC_LIB_DIR)/libgcc.a -o $@

%.hex: %.elf
	./firmware_words $< -ram $(RAM_SIZE) -max_addr 65535 -hex $@
	cp $@ ../firmware.hex
	mkdir -p ../obj_dir
	cp $@ ../obj_dir/firmware.hex
	echo $@ > ../firmware.txt


# SPI FLASH 0 (sends everything to SPI flash)

%.spiflash0.elf: %.o start.o $(LIBOBJECTS)
	$(RVLD) -T spiflash0.ld -m elf32lriscv -nostdlib -norelax $< $(LIBOBJECTS) $(RVTOOLCHAIN_GCC_LIB_DIR)/libgcc.a -o $@

%.spiflash0.bin: %.spiflash0.elf
	$(RVOBJCOPY) $< $@ -O binary

%.spiflash0.prog: %.spiflash0.bin
	iceprog -o 128k $<

# SPI FLASH 1 (sends code and variables initialization to SPI flash, variables to RAM)

%.spiflash1.elf: %.o start_spiflash1.o $(LIBOBJECTS)
	$(RVLD) -T spiflash1.ld -m elf32lriscv -nostdlib -norelax $< $(LIBOBJECTS) $(RVTOOLCHAIN_GCC_LIB_DIR)/libgcc.a -o $@


%.spiflash1.bin: %.spiflash1.elf
	$(RVOBJCOPY) $< $@ -O binary

%.spiflash1.prog: %.spiflash1.bin
	iceprog -o 128k $<


# SPI FLASH 2 (sends code and variables initialization to SPI flash, variables and fastcode to RAM)

%.spiflash2.elf: %.o start_spiflash1.o $(LIBOBJECTS)
	$(RVLD) -T spiflash2.ld -m elf32lriscv -nostdlib -norelax $< $(LIBOBJECTS) -L$(RVTOOLCHAIN_LIB_DIR) -lm  $(RVTOOLCHAIN_GCC_LIB_DIR)/libgcc.a -o $@


%.spiflash2.bin: %.spiflash2.elf
	$(RVOBJCOPY) $< $@ -O binary

%.spiflash2.prog: %.spiflash2.bin
	iceprog -o 128k $<

%.spiflash2.list: %.spiflash2.elf
	$(RVOBJDUMP) -Mnumeric -D $< > $@

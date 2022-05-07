verilator -CFLAGS '-I../LIBFEMTORV32 -DSTANDALONE_FEMTOELF' -DBENCH -DBOARD_FREQ=10 -DCPU_FREQ=10 -DPASSTHROUGH_PLL -Wno-fatal \
	  --top-module SOC -cc -exe sim_main.cpp ../LIBFEMTORV32/femto_elf.c $1
(cd obj_dir; rm -f *.o *.a VSOC; make -f VSOC.mk)
obj_dir/VSOC $2


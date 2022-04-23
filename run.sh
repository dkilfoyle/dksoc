BOARD_FREQ=12
CPU_FREQ=45
rm -f a.out
iverilog -DBENCH -DSIM -DBOARD_FREQ=10 -DCPU_FREQ=10 bench_iverilog.v soc.v $2
vvp a.out

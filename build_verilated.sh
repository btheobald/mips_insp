verilator --cc --sv --exe --trace --top-module core -f pico.flist tb_core.cpp -CFLAGS "-std=gnu++11 -DVCD_TRACE"
make -C obj_dir -f Vcore.mk
mv obj_dir/Vcore Vcore

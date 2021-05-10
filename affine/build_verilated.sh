verilator --cc --sv --exe -Wno-lint --trace --top-module core common.sv core.sv tb_core.cpp -CFLAGS "-std=gnu++11 -DVCD_TRACE"
make -C obj_dir -f Vcore.mk
mv obj_dir/Vcore Vcore

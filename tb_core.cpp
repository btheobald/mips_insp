#include <verilated.h>
#include <iostream>
#include "Vcore.h"
#include <verilated_vcd_c.h>

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vcore* top = new Vcore;

    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("test.vcd");

    top->n_rst_i = 0;
    top->ext_data_i = 0;    

    while(!Verilated::gotFinish() && main_time < 1000 && (top->halt_o == 0)) {
        if(main_time > 10) {
            top->n_rst_i = 1;
        }
        if((main_time % 10) == 0) {
            top->clk_i ^= 1;
        }
        top->eval();
        //std::cout << main_time << " " << top->result_o << std::endl;
        main_time++;
        tfp->dump(main_time);
    }

    for(int i = 0; i < 20; i++) {
        if((main_time % 10) == 0) {
            top->clk_i ^= 1;
        }
        top->eval();
        main_time++;
        tfp->dump(main_time);
    }

    std::cout << "Core Halted" << std::endl;
    tfp->close();

    top->final();

    delete top;

    return 0;
}

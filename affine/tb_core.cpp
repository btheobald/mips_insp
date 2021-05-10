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

    int idx = 0;
    int8_t vals[120] = {-50,100,-40,100,-30,100,-20,100,-10,100,0,100,10,100,20,100,30,100,40,100,50,100,    // Right
                         50,90,50,80,50,70,50,60,50,50,50,40,50,30,50,20,50,10,50,0,50,-10,50,-20,50,-30,50,-40,50,-50,50,-60,50,-70,50,-80,50,-90,50,-100, // Down
                         40,-100,30,-100,20,-100,10,-100,0,-100,-10,-100,-20,-100,-30,-100,-40,-100,-50,-100, // Left
                         -50,-90,-50,-80,-50,-70,-50,-60,-50,-50,-50,-40,-50,-30,-50,-20,-50,-10,-50,0,-50,10,-50,20,-50,30,-50,40,-50,50,-50,60,-50,70,-50,80,-50,90}; // Up
    int8_t xval[60] = {0};
    int8_t yval[60] = {0};
    int8_t xyval = 0;

    top->ext_data_i = vals[idx%120];
    top->n_rst_i = 1;
    while(!Verilated::gotFinish() && idx <= 120) {
        if(top->halt_o == 1) {
            top->n_rst_i = 0; 
           
            if((idx != 0) && (idx % 2 == 0)) {
                xval[xyval] = top->ext_data_o;

                top->eval();
                top->clk_i ^= 1;
                main_time++;

                tfp->dump(main_time);

                yval[xyval] = top->ext_data_o;
                xyval++;
            } else {
                top->eval();
                top->clk_i ^= 1;
                main_time++;
                tfp->dump(main_time);
            }
            
            top->clk_i ^= 1;

            top->ext_data_i = vals[idx%120];
            idx++;
            top->n_rst_i = 1;
        } else {
            top->clk_i ^= 1;
        }

        top->eval();
        
        main_time++;
        tfp->dump(main_time);
    }

    for(int i = 0; i < 20; i++) {
        if((main_time % 1) == 0) {
            top->clk_i ^= 1;
        }
        top->eval();
        main_time++;
        tfp->dump(main_time);
    }

    std::cout << "Core Halted" << std::endl;
    tfp->close();
    
    for(int i = 0; i < 60; i++) {
        printf("%d\t%d\n", xval[i], yval[i]);
    }

    top->final();

    delete top;

    return 0;
}

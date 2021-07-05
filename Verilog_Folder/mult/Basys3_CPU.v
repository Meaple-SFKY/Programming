`timescale 1ns / 1ps

module Basys3_CPU(
    input basys3_clock,
    input reset_sw,
    input [1:0] SW_in,
    input next_button,
    output [3:0] enable,
    output [7:0] dispcode
    );
    
    wire [31:0] currentIAddr, nextIAddr;
    wire [4:0] rs, rt;
    wire [31:0] ReadData1, ReadData2;
    wire [31:0] ALU_result, DataBus;
    
    wire next_signal;    // 消抖后的手动脉冲信号
    wire [15:0] DisplayData;
    
    top_CPU top_CPU(
        .clk(next_signal),    // 取反，使得按下按钮提供低电平，松开后PC才递增
        .Reset(reset_sw),
        .currentIAddr(currentIAddr), .nextIAddr(nextIAddr),
        .rs(rs), .rt(rt),
        .ReadData1(ReadData1), .ReadData2(ReadData2),
        .ALU_result(ALU_result), .DataBus(DataBus)
    );
        
    
    Mux4_16bits Mux4_16bits(
        .choice(SW_in),
        .in0({currentIAddr[7:0], nextIAddr[7:0]}),
        .in1({3'b000, rs, ReadData1[7:0]}),
        .in2({3'b000, rt, ReadData2[7:0]}),
        .in3({ALU_result[7:0], DataBus[7:0]}),
        .out(DisplayData)
    );
endmodule

`include "top_CPU.v"

`timescale 1ns / 1ps

module CPU_sim_1;
    reg clk, Reset;
    wire [31:0] currentIAddr, nextIAddr;
    wire [4:0] rs, rt;
    wire [31:0] ReadData1, ReadData2;
    wire [31:0] ALU_result, DataBus;
    
    top_CPU uut(
        .clk(clk),
        .Reset(Reset),
        .currentIAddr(currentIAddr), .nextIAddr(nextIAddr),
        .rs(rs), .rt(rt),
        .ReadData1(ReadData1), .ReadData2(ReadData2),
        .ALU_result(ALU_result), .DataBus(DataBus)
    );
    
    always #50 clk = ~clk;    // 仿真时钟周期为100ns
    
    initial begin
        $dumpfile("test.vcd");
		$dumpvars(0, CPU_sim_1);
        clk = 1;
        Reset = 0;
        #25;
        Reset = 1;    // 开始仿真
        #11000;        // 进行11000ns的仿真
        $stop;  // 断点
    end
endmodule

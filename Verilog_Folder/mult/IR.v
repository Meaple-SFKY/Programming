`timescale 1ns / 1ps


module IR(//将指令锁存
    input clk,
    input IRWre,//IR的使能信号
    input [31:0] insIn,//输入指令，将当前指令存储起来
    output reg [31:0] insOut
    );
    
    always @(negedge clk) begin
        insOut <= insIn;//指令输出
    end
    
endmodule

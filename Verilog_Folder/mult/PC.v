`timescale 1ns / 1ps

module PC(
    input clk,
    input Reset,
    input PCWre,//取址使能信号
    input [31:0] nextIAddr,//下一条指令的地址
    output reg [31:0] currentIAddr//输出当前指令
    );
    
    initial currentIAddr <= 0;//初始化
    
    always @(posedge clk or negedge Reset) begin
        if(Reset == 0) currentIAddr <= 0;//复位信号，当前指令地址置零
        else begin
            if(PCWre == 1) currentIAddr <= nextIAddr;//取下一条指令
            else currentIAddr <= currentIAddr;//指令保持不变
        end
    end
endmodule

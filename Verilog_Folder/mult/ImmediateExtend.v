`timescale 1ns / 1ps

module ImmediateExtend(//将16位立即数扩展为32位
    input [15:0] original,//立即数
    input ExtSel,//扩展选择信号，为0则高位扩展为0，为1则根据立即数最高位扩展
    output reg [31:0] extended//输出扩展后的32位立即数
    );
    
    always @(*) begin
        extended[15:0] <= original;//立即数传入低16位
        if(ExtSel == 0) begin
            extended[31:16] <= 0;//高位扩展为0
        end
        else begin
            if(original[15] == 0) extended[31:16] <= 0;//立即数最高位为0则扩展为0
            else extended[31:16] <= 16'hFFFF;//为1则扩展为1
        end
    end
    
endmodule

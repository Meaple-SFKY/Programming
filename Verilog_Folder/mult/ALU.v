`timescale 1ns / 1ps

module ALU(
    input [2:0] ALUOp,//alu操作码
    input [31:0] A,
    input [31:0] B,
    output reg [31:0] result,
    output zero,// 结果是否为0？是为1，否为0
    output sign// 结果是否为负？是为1，否为0
    );
    
    assign zero = (result == 0) ? 1 : 0;
    assign sign = result[31];
    
    always @(ALUOp or A or B) begin
        case(ALUOp)
            3'b000: result = A + B;//加法
            3'b001: result = A - B;//减法
            3'b010: result = B << A;//B左移A位
            3'b011: result = A | B;//或运算
            3'b100: result = A & B;//与运算
            3'b101: result = (A < B) ? 1 : 0; //比较无符号数
            3'b110: begin//比较带符号数
                if((A[31] == B[31]) && (A < B)) result = 1;
                else if(A[31]==1 && B[31]==0) result = 1;
                else result = 0;
                end
            3'b111: result = A ^ B;//异或运算
        endcase
    end
endmodule

`timescale 1ns / 1ps

module InstructionMemory(
    input [31:0] IAddr,
    //input [31:0] IDataIn,
    //input RW,    // ָ��洢����д�����źţ�Ϊ0д��Ϊ1��
    output [31:0] IDataOut
    );
    
    reg [7:0] ROM [0:127];
    
    initial begin
        $readmemb("./test_instructions.txt", ROM);
    end
    
    assign IDataOut[31:24] = ROM[IAddr+0];
    assign IDataOut[23:16] = ROM[IAddr+1];
    assign IDataOut[15:8]  = ROM[IAddr+2];
    assign IDataOut[7:0]   = ROM[IAddr+3];
    
endmodule

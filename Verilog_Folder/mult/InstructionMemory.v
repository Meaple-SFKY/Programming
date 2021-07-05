`timescale 1ns / 1ps

module InstructionMemory(
    input [31:0] IAddr,//输入指令的地址
    //input [31:0] IDataIn,
    //input RW,    // 指令存储器读写控制信号，为0写，为1读
    output [31:0] IDataOut//取出的指令
    );
    
    reg [7:0] ROM [0:127];//定义8位的指令存储器堆
    
    initial begin
        //$readmemb("C:/Users/lenovo/Desktop/multiCycleCPUNew/test_instructions.txt", ROM);//从文件中读取指令，存放到指令存储器堆中
        ROM[0] = 8'b00000000;//add
        ROM[1] = 8'b00100010;//寄存器1、寄存器2
        ROM[2] = 8'b00011000;//寄存器3
        ROM[3] = 8'b00000000;//保留
        
        ROM[4] = 8'b00001000;//addiu
        ROM[5] = 8'b00100010;//寄存器1、寄存器2
        ROM[6] = 8'b00000010;//立即数
        ROM[7] = 8'b00100100;
       
        
        
        
        
    end
    
    assign IDataOut[31:24] = ROM[IAddr+0];//通过指令的地址来从存储器堆中取指令
    assign IDataOut[23:16] = ROM[IAddr+1];
    assign IDataOut[15:8]  = ROM[IAddr+2];
    assign IDataOut[7:0]   = ROM[IAddr+3];
    
endmodule

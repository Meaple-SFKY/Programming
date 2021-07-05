`timescale 1ns / 1ps

module RegisterFile(
    input clk,
    input Reset,
    input WE,// 寄存器堆写使能信号，1为有效
    input [4:0] ReadReg1,//操作数1存放的寄存器
    input [4:0] ReadReg2,//操作数2存放的寄存器
    input [4:0] WriteReg,//写回数据存放的寄存器
    input [31:0] WriteData,//写回的数据
    output [31:0] ReadData1,//操作数1
    output [31:0] ReadData2//操作数2
    );
    
    reg [31:0] file [1:31];//寄存器堆
    integer i;
    
    assign ReadData1 = (ReadReg1 == 0) ? 0 : file[ReadReg1];//从寄存器堆中取数据，操作数1
    assign ReadData2 = (ReadReg2 == 0) ? 0 : file[ReadReg2];//操作数2
    
    always @(negedge clk or negedge Reset) begin
        if(Reset == 0) begin//复位信号，寄存器堆置0
            /*for(i = 1; i <= 31; i=i+1) begin
                file[i] <= 0;
            end*/
            file[1] = 5;
            file[2] = 6;
        end
        else if(WE == 1 && WriteReg != 0)//写使能信号为1，
            file[WriteReg] <= WriteData;//写入数据
    end
    
endmodule

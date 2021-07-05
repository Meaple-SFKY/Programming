`timescale 1ns / 1ps

module RegisterFile(
    input clk,
    input Reset,
    input WE,// �Ĵ�����дʹ���źţ�1Ϊ��Ч
    input [4:0] ReadReg1,//������1��ŵļĴ���
    input [4:0] ReadReg2,//������2��ŵļĴ���
    input [4:0] WriteReg,//д�����ݴ�ŵļĴ���
    input [31:0] WriteData,//д�ص�����
    output [31:0] ReadData1,//������1
    output [31:0] ReadData2//������2
    );
    
    reg [31:0] file [1:31];//�Ĵ�����
    integer i;
    
    assign ReadData1 = (ReadReg1 == 0) ? 0 : file[ReadReg1];//�ӼĴ�������ȡ���ݣ�������1
    assign ReadData2 = (ReadReg2 == 0) ? 0 : file[ReadReg2];//������2
    
    always @(negedge clk or negedge Reset) begin
        if(Reset == 0) begin//��λ�źţ��Ĵ�������0
            /*for(i = 1; i <= 31; i=i+1) begin
                file[i] <= 0;
            end*/
            file[1] = 5;
            file[2] = 6;
        end
        else if(WE == 1 && WriteReg != 0)//дʹ���ź�Ϊ1��
            file[WriteReg] <= WriteData;//д������
    end
    
endmodule

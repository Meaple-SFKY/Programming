`timescale 1ns / 1ps

module InstructionMemory(
    input [31:0] IAddr,//����ָ��ĵ�ַ
    //input [31:0] IDataIn,
    //input RW,    // ָ��洢����д�����źţ�Ϊ0д��Ϊ1��
    output [31:0] IDataOut//ȡ����ָ��
    );
    
    reg [7:0] ROM [0:127];//����8λ��ָ��洢����
    
    initial begin
        //$readmemb("C:/Users/lenovo/Desktop/multiCycleCPUNew/test_instructions.txt", ROM);//���ļ��ж�ȡָ���ŵ�ָ��洢������
        ROM[0] = 8'b00000000;//add
        ROM[1] = 8'b00100010;//�Ĵ���1���Ĵ���2
        ROM[2] = 8'b00011000;//�Ĵ���3
        ROM[3] = 8'b00000000;//����
        
        ROM[4] = 8'b00001000;//addiu
        ROM[5] = 8'b00100010;//�Ĵ���1���Ĵ���2
        ROM[6] = 8'b00000010;//������
        ROM[7] = 8'b00100100;
       
        
        
        
        
    end
    
    assign IDataOut[31:24] = ROM[IAddr+0];//ͨ��ָ��ĵ�ַ���Ӵ洢������ȡָ��
    assign IDataOut[23:16] = ROM[IAddr+1];
    assign IDataOut[15:8]  = ROM[IAddr+2];
    assign IDataOut[7:0]   = ROM[IAddr+3];
    
endmodule

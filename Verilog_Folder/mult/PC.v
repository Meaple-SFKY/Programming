`timescale 1ns / 1ps

module PC(
    input clk,
    input Reset,
    input PCWre,//ȡַʹ���ź�
    input [31:0] nextIAddr,//��һ��ָ��ĵ�ַ
    output reg [31:0] currentIAddr//�����ǰָ��
    );
    
    initial currentIAddr <= 0;//��ʼ��
    
    always @(posedge clk or negedge Reset) begin
        if(Reset == 0) currentIAddr <= 0;//��λ�źţ���ǰָ���ַ����
        else begin
            if(PCWre == 1) currentIAddr <= nextIAddr;//ȡ��һ��ָ��
            else currentIAddr <= currentIAddr;//ָ��ֲ���
        end
    end
endmodule

`timescale 1ns / 1ps

module ImmediateExtend(//��16λ��������չΪ32λ
    input [15:0] original,//������
    input ExtSel,//��չѡ���źţ�Ϊ0���λ��չΪ0��Ϊ1��������������λ��չ
    output reg [31:0] extended//�����չ���32λ������
    );
    
    always @(*) begin
        extended[15:0] <= original;//�����������16λ
        if(ExtSel == 0) begin
            extended[31:16] <= 0;//��λ��չΪ0
        end
        else begin
            if(original[15] == 0) extended[31:16] <= 0;//���������λΪ0����չΪ0
            else extended[31:16] <= 16'hFFFF;//Ϊ1����չΪ1
        end
    end
    
endmodule

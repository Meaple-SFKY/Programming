`timescale 1ns / 1ps


module IR(//��ָ������
    input clk,
    input IRWre,//IR��ʹ���ź�
    input [31:0] insIn,//����ָ�����ǰָ��洢����
    output reg [31:0] insOut
    );
    
    always @(negedge clk) begin
        insOut <= insIn;//ָ�����
    end
    
endmodule

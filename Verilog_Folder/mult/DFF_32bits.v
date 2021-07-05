`timescale 1ns / 1ps

module DFF_32bits(
    input clk,
    input Reset,
    input [31:0] in,
    output reg [31:0] out
    );
    
    always @(posedge clk/* or negedge Reset*/) begin
        //if(Reset==0) out <= 0;
        /*else*/ out <= in;
    end
    
endmodule

`timescale 1ns / 1ps

module IR(
    input clk,
    input IRWre,
    input [31:0] insIn,
    output reg [31:0] insOut
    );
    
    always @(negedge clk) begin
        /*if(IRWre==1)*/ insOut <= insIn;
       /* else insOut <= insOut;*/
    end
    
endmodule

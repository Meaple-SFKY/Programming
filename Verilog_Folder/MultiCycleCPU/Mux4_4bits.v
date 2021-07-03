`timescale 1ns / 1ps

module Mux4_4bits(
    input [1:0] choice,
    input [3:0] in0, in1, in2, in3,
    output reg [3:0] out
    );
    
    always @(*) begin
        case(choice)
            0: out <= in0;
            1: out <= in1;
            2: out <= in2;
            3: out <= in3;
        endcase
    end
    
endmodule

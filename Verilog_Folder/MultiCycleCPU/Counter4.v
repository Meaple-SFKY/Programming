`timescale 1ns / 1ps

module Counter4(
    input clk,
    output reg [1:0] count
    );
    
    always @(posedge clk) begin
        if(count == 2'b11) count <= 0;
        else count <= count + 1;
    end
    
endmodule

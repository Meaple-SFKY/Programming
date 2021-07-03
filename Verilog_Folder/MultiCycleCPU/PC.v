`timescale 1ns / 1ps

module PC(
    input clk,
    input Reset,
    input PCWre,
    input [31:0] nextIAddr,
    output reg [31:0] currentIAddr
    );
    
    initial currentIAddr <= 0;
    
    always @(posedge clk or negedge Reset) begin
        if(Reset == 0) currentIAddr <= 0;
        else begin
            if(PCWre == 1) currentIAddr <= nextIAddr;
            else currentIAddr <= currentIAddr;
        end
    end
endmodule

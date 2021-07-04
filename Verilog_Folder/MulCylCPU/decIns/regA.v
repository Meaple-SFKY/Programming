module regAMod (
	input wire clk,
	input wire [31:0] regFilOutA,
	output reg [31:0] regAOut
);
	
	always @(negedge clk) begin
		regAOut = regFilOutA;
	end

endmodule
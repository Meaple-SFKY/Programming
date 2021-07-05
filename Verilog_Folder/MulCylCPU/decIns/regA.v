module regAMod (
	input wire clk,
	input wire [31:0] regFilOutA,
	output reg [31:0] regAOut
);
	
	always @(negedge clk) begin
		assign regAOut = regFilOutA;
	end

endmodule
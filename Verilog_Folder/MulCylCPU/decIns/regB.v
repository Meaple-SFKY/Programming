module regBMod (
	input wire clk,
	input wire [31:0] regFilOutB,
	output reg [31:0] regBOut
);
	
	always @(negedge clk) begin
		regBOut = regFilOutB;
	end

endmodule
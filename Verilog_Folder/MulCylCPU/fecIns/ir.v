module irMod (
	input wire [31:0] insMemOut,
	output reg [5:0] irOutOpe,
	output reg [25:0] irOutOth
);
	
	always @* begin
		irOutOpe = insMemOut[31:26];
		irOutOth = insMemOut[25:0];
	end

endmodule
module insMemMod (
	input wire clk,
	input wire [31:0] pcOut,
	output reg [31:0] insMemOut
);
	
	reg [31:0] unit [0:65535];

	initial begin
		
	end

	always @(negedge clk) begin
		insMemOut = unit[pcOut];
	end

endmodule
module pcMod (
	input wire clk, rst,
	input wire [31:0] pcInp,
	output reg [31:0] pcOut
);
	
	initial begin
		pcOut = 0;
	end

	always @(posedge clk) begin
		pcOut = pcInp;
	end

endmodule
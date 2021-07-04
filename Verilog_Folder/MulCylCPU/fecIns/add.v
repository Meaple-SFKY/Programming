module addMod (
	input wire clk,
	input wire [31:0] pcOut,
	output reg [31:0] addOut
);
	
	initial begin
		assign addOut = 0;
	end

	always @(negedge clk) begin
		assign addOut = pcOut + 4;
	end

endmodule
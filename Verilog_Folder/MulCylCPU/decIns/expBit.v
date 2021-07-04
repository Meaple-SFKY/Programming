module expBitMod (
	input wire clk,
	input wire [15:0] irOutImm,
	output reg [31:0] expBitOut
);
	
	reg sig;

	initial begin
		assign sig = irOutImm[15];
	end

	always @* begin
		if (sig == 0) begin
			expBitOut[31:16] = 0;
		end else begin
			expBitOut[31:16] = 16'hffff;
		end
	end

	always @(negedge clk) begin
		expBitOut[15:0] = irOutImm;
	end

endmodule
module muxThiMod (
	input wire muxThiSig,
	input wire [31:0] regBOut,
	input wire [31:0] expBitOut,
	output reg [31:0] muxThiOut
);

	always @* begin
		if (muxThiSig == 0) begin
			assign muxThiOut = regBOut;
		end else begin
			assign muxThiOut = expBitOut;
		end
	end

endmodule
module muxSecMod (
	input wire muxSecSig,
	input wire [31:0] regAOut, npcOut,
	output reg [31:0] muxSecOut
);

	always @* begin
		if (muxSecSig == 0) begin
			assign muxSecOut = regAOut;
		end else begin
			assign muxSecOut = npcOut;
		end
	end

endmodule
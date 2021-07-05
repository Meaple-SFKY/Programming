`include "../wriBac/muxFor.v"

module wriBacMod (
	input wire clk, wbSig,
	input wire [31:0] aluOOut, lmdOut,
	output wire [31:0] muxForOut
);
	
	muxForMod muxFor(
		.clk(clk), .wbSig(wbSig),
		.aluOOut(aluOOut), .lmdOut(lmdOut),
		.muxForOut(muxForOut)
	);

endmodule
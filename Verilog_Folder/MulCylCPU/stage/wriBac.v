`include "../wriBac/muxFor.v"

module wriBacMod (
	input wire wbSig,
	input wire [31:0] aluOOut, lmdOut,
	output wire [31:0] muxForOut
);
	
	muxForMod muxFor(
		.wbSig(wbSig),
		.aluOOut(aluOOut), .lmdOut(lmdOut),
		.muxForOut(muxForOut)
	);

endmodule
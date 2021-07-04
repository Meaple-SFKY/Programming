`include "../accMem/muxFir.v"
`include "../accMem/datMem.v"
`include "../accMem/lmd.v"

module accMemMod (
	input wire clk, condOut, datMemWr,
	input wire [31:0] aluOOut, npcOut, regBOut,
	output wire [31:0] muxFirOut, lmdOut
);
	
	wire [31:0] datMemOut;

	muxFirMod muxFir (
		.condOut(condOut),
		.aluOOut(aluOOut), .npcOut(npcOut),
		.muxFirOut(muxFirOut)
	);

	datMemMod datMem (
		.clk(clk), .datMemWr(datMemWr),
		.aluOOut(aluOOut), .regBOut(regBOut),
		.datMemOut(datMemOut)
	);

	lmdMod lmd(
		.datMemOut(datMemOut),
		.lmdOut(lmdOut)
	);

endmodule
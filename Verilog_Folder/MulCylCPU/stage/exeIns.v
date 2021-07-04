`include "../exeIns/muxSec.v"
`include "../exeIns/muxThi.v"
`include "../exeIns/alu.v"
`include "../exeIns/aluo.v"
`include "../exeIns/cond.v"

module exeInsMod (
	input wire clk, muxSecSig, muxThiSig,
	input wire [5:0] funct,
	input wire [31:0] regAOut, regBOut, npcOut, expBitOut,
	output wire condOut,
	output wire [31:0] aluOOut
);
	
	wire [31:0] muxSecOut, muxThiOut, aluOut;

	muxSecMod muxSec(
		.muxSecSig(muxSecSig),
		.regAOut(regAOut), .npcOut(npcOut),
		.muxSecOut(muxSecOut)
	);

	muxThiMod muxThi(
		.muxThiSig(muxThiSig),
		.regBOut(regBOut), .expBitOut(expBitOut),
		.muxThiOut(muxThiOut)
	);

	aluMod alu(
		.clk(clk),
		.funct(funct),
		.muxSecOut(muxSecOut), .muxThiOut(muxThiOut),
		.aluOut(aluOut)
	);

	aluOMod aluo(
		.clk(clk),
		.aluOut(aluOut),
		.aluOOut(aluOOut)
	);

	condMod cond(
		.regAOut(regAOut),
		.condOut(condOut)
	);

endmodule
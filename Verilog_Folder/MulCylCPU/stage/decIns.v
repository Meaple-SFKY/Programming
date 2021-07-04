`include "../decIns/uniRegFil.v"
`include "../decIns/regA.v"
`include "../decIns/regB.v"
`include "../decIns/expBit.v"

module decInsMod (
	input wire clk, ifWR, wriReg, rst,
	input wire [26:0] irOutOth,
	input wire [31:0] muxForOut,
	output wire [31:0] regAOut, regBOut, expBitOut
);
	
	wire [4:0] irOutRs, irOutRt, irOutRd;
	wire [15:0] irOutImm;
	wire [31:0] regFilOutA, regFilOutB;

	assign irOutRs = irOutOth[26:22];
	assign irOutRt = irOutOth[21:17];
	assign irOutRd = irOutOth[16:12];
	assign irOutImm = irOutOth[15:0];

	uniRegFilMod regFile (
		.clk(clk), .ifWR(ifWR), .wriReg(wriReg), .rst(rst),
		.irOutRs(irOutRs), .irOutRt(irOutRt), .irOutRd(irOutRd),
		.muxForOut(muxForOut),
		.regFilOutA(regFilOutA), .regFilOutB(regFilOutB)
	);

	regAMod regA(
		.clk(clk),
		.regFilOutA(regFilOutA),
		.regAOut(regAOut)
	);

	regBMod regB(
		.clk(clk),
		.regFilOutB(regFilOutB),
		.regBOut(regBOut)
	);

	expBitMod expBit(
		.clk(clk),
		.irOutImm(irOutImm),
		.expBitOut(expBitOut)
	);

endmodule
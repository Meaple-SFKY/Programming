`include "../fecIns/pc.v"
`include "../fecIns/add.v"
`include "../fecIns/insMem.v"
`include "../fecIns/ir.v"
`include "../fecIns/npc.v"

module fecIns (
	input wire clk, rst,
	input wire [31:0] muxFirOut,
	output wire [5:0] irOutOpe,
	output wire [25:0] irOutOth,
	output wire [31:0] npcOut
);
	
	wire [31:0] pcOut, addOut;
	wire [31:0] insMemOut;

	pcMod pc(
		.clk(clk), .rst(rst),
		.pcInp(muxFirOut),
		.pcOut(pcOut)
	);

	addMod add(
		.clk(clk),
		.pcOut(pcOut),
		.addOut(addOut)
	);

	insMemMod insMem(
		.clk(clk),
		.pcOut(pcOut),
		.insMemOut(insMemOut)
	);

	npcMod npc(
		.addOut(addOut),
		.npcOut(npcOut)
	);

	irMod ir(
		.insMemOut(insMemOut),
		.irOutOpe(irOutOpe),
		.irOutOth(irOutOth)
	);

endmodule
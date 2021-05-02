`include "PC.v"
`include "INSREG.v"
`include "ACC.v"
`include "MEMOR.v"
`include "CTRLUNIT.v"
`include "ALU.v"

module CPU (
	input wire clk, rst
);

	wire stop, pcWR, accWR, memWR, insMode, ifBan;
	wire [2 : 0] insShort;
	wire [3 : 0] aluCode, insLong;
	wire [7 : 0] Addr, dataAddr;
	wire [15 : 0] inDataA, inDataB, aluData;

	PC pc (
		.clk(clk), .rst(rst), .stop(stop), .pcWR(pcWR), .ifBan(ifBan),
		.jump(dataAddr[7 : 0]), .Addr(Addr)
	);

	INSREG insreg (
		.Addr(Addr),
		.insMode(insMode),
		.insShort(insShort),
		.insLong(insLong),
		.dataAddr(dataAddr)
	);

	ACC acc (
		.clk(clk), .accWR(accWR),
		.inData(aluData),
		.outData(inDataA)
	);

	MEMOR memor (
		.memWR(memWR), .clk(clk),
		.dataAddr(dataAddr[7 : 0]),
		.inData(aluData),
		.outData(inDataB)
	);

	CTRLUNIT cu (
		.insShort(insShort),
		.insLong(insLong),
		.insMode(insMode),
		.stop(stop), .pcWR(pcWR), .accWR(accWR), .memWR(memWR),
		.aluCode(aluCode)
	);

	ALU alu (
		.aluCode(aluCode),
		.inDataA(inDataA), .inDataB(inDataB),
		.ifBan(ifBan),
		.aluData(aluData)
	);

endmodule
`include "regFile.v"

module tb;
	reg[2:0] addrA, addrB, inAddr;
	wire[15:0] outA, outB;
	reg[15:0] inData;
	reg WE, clk;

	always#5 clk = ~clk;

	initial begin
		$dumpfile("test.vcd");
		$dumpvars(0, tb);

		addrA = 3'b000;
		addrB = 3'b001;
		inAddr = 3'b000;
		inData = 16'h0000;
		WE = 0;
		clk = 0;

		#10
		addrA = 3'b010;
		addrB = 3'b011;

		#10
		inData = 16'h00ff;
		inAddr = 3'b100;
		WE = 1;

		#10
		inData = 16'h00ee;
		inAddr = 3'b101;

		#10
		WE = 0;
		addrA = 3'b100;
		addrB = 3'b101;

		#10
		$stop;
		$finish;

	end

	regFile file(
		.addrA(addrA), .addrB(addrB), .inAddr(inAddr),
		.outA(outA), .outB(outB),
		.inData(inData),
		.WE(WE), .clk(clk)
	);

endmodule
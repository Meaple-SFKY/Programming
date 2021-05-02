module regFile (
	input wire[2:0] addrA, addrB, inAddr,
	output wire[15:0] outA, outB,
	input wire[15:0] inData,
	input WE, clk
);

	reg[15:0] regs[0:7];

	initial begin
		regs[0] = 0;
		regs[1] = 16'h0001;
		regs[2] = 16'h0002;
		regs[3] = 16'h0003;
	end

	assign outA = regs[addrA];
	assign outB = regs[addrB];

	always@(negedge clk) begin
		if(WE == 1)
			regs[inAddr] = inData;
	end

endmodule
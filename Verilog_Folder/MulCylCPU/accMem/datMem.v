module datMemMod (
	input wire clk, datMemWr,
	input wire [31:0] aluOOut, regBOut,
	output reg [31:0] datMemOut
);
	
	reg [7:0] dataMem [0:127];

	always @(posedge clk) begin
		assign datMemOut = 32'bx;
		if (datMemWr == 1) begin
			dataMem[aluOOut] = regBOut[31:25];
			dataMem[aluOOut + 1] = regBOut[24:16];
			dataMem[aluOOut + 2] = regBOut[15:8];
			dataMem[aluOOut + 3] = regBOut[7:0];
		end
	end

	always @(negedge clk) begin
		if (datMemWr == 0) begin
			assign datMemOut[31:25] = dataMem[aluOOut];
			assign datMemOut[24:16] = dataMem[aluOOut + 1];
			assign datMemOut[15:8] = dataMem[aluOOut + 2];
			assign datMemOut[7:0] = dataMem[aluOOut + 3];
		end else begin
			assign datMemOut = 32'bx;
		end
	end
endmodule
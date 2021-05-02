module ALU (
	input wire [15 : 0] inDataA, inDataB,
	input wire [3 : 0] aluCode,
	output reg [15 : 0] aluData,
	output reg ifBan
);

	initial begin
		ifBan = 0;
		aluData = 0;
	end

	always @* begin
		if (ifBan == 1) begin
			#2
			ifBan = ~ifBan;
		end
	end

	always @* begin
		case (aluCode)
			4'b0000: aluData = 0;
			4'b0001: aluData = ~inDataA;
			4'b0010: aluData = (inDataA >>> 1);
			4'b0011: aluData = {inDataA[14 : 0], inDataA[15]};
			4'b0100: aluData = inDataA + inDataB;
			4'b0101: aluData = inDataA;
			4'b0110: aluData = inDataB;
			4'b0111: ifBan = inDataA[15] == 1 ? 1 : 0;
		endcase
	end
endmodule
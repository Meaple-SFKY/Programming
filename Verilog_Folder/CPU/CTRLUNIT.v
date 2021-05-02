module CTRLUNIT (
	input wire [3 : 0] insLong,
	input wire [2 : 0] insShort,
	input wire insMode,
	output reg stop, pcWR, accWR, memWR,
	output reg [3 : 0] aluCode
);

	initial begin
		stop = 0;
		pcWR = 0;
		accWR = 0;
		memWR = 0;
		aluCode = 4'bX;
	end

	always @(insMode, insShort, insLong) begin
		if (insMode == 0) begin
			case (insShort)
				3'b001: {stop, pcWR, accWR, memWR, aluCode} = 8'b00010101;	//001	sta
				3'b010: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100110;	//010	lda
				3'b011: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100000;	//011	cla
				3'b100: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100001;	//100	com
				3'b101: {stop, pcWR, accWR, memWR, aluCode} = 8'b01001111;	//101	jmp
			endcase
		end else begin
			case (insLong)
				4'b1000: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100100;	//1000	add
				4'b1100: {stop, pcWR, accWR, memWR, aluCode} = 8'b01000111;	//1100	ban
				4'b1101: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100010;	//1101	shr
				4'b1110: {stop, pcWR, accWR, memWR, aluCode} = 8'b00100011;	//1110	csl
				4'b1111: {stop, pcWR, accWR, memWR, aluCode} = 8'b10101111;	//1111	stp
			endcase
		end
	end

endmodule
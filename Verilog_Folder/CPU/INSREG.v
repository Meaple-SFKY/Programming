module INSREG (
	input wire [7 : 0] Addr,
	output reg [3 : 0] insLong,
	output reg [2 : 0] insShort,
	output reg insMode,
	output reg [7 : 0] dataAddr
);

	reg [11 : 0] unit[8'b11111111:0];
	reg [11 : 0] ins;

	initial begin
		unit[0] = 11'b01000000001;		// lda
		unit[1] = 12'b100000000010;		// add
		unit[2] = 4'b1110;				// csl
		unit[3] = 4'b1101;				// shr
		unit[4] = 3'b100;				// com
		unit[5] = 3'b011;				// cla
		unit[6] = 11'b01000000010;		// lda
		unit[7] = 4'b1110;				// csl
		unit[8] = 12'b100000001011;		// add
		unit[9] = 11'b00100000010;		// sta
		unit[10] = 12'b110000000010;	// ban
		unit[11] = 12'b100000001011;	// add
		unit[12] = 11'b10100001110;		// jmp
		unit[13] = 12'b100000001011;	// add
		unit[14] = 4'b1111;				// stp
	end

	always @* begin
		ins = unit[Addr];
		if (ins[11 : 9] == 0) begin
			if (ins[8] == 0) begin
				if (ins[3] == 0) begin
					{insMode, insShort, insLong, dataAddr} = {1'b0, ins[2 : 0], 4'b0000, 8'b00000000};	// cla com
				end else begin
					{insMode, insShort, insLong, dataAddr} = {1'b1, 3'b000, ins[3 : 0], 8'b00000000};	// csl shr stp
				end
			end else begin
				{insMode, insShort, insLong, dataAddr} = {1'b0, ins[10 : 8], 4'b0000, ins[7 : 0]};		// sta
			end
		end else begin
			if (ins[11] == 0) begin
				{insMode, insShort, insLong, dataAddr} = {1'b0, ins[10 : 8], 4'b0000, ins[7 : 0]};		// lda jmp
			end else begin
				{insMode, insShort, insLong, dataAddr} = {1'b1, 3'b000, ins[11 : 8], ins[7 : 0]};		// ban add
			end
		end
	end

endmodule
module npcMod (
	input wire [31:0] addOut,
	output reg [31:0] npcOut
);
	
	initial begin
		assign npcOut = 0;
	end

	always @* begin
		assign npcOut = addOut;
	end

endmodule
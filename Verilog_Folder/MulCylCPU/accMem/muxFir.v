module muxFirMod (
	input wire condOut,
	input wire [31:0] aluOOut, npcOut,
	output reg [31:0] muxFirOut
);
	
	always @* begin
		if (condOut == 0) begin
			assign muxFirOut = npcOut;
		end else begin
			assign muxFirOut = aluOOut;
		end
	end

endmodule
module condMod (
	input wire [31:0] regAOut,
	output reg condOut
);
	
	always @* begin
		if (regAOut == 0) begin
			assign condOut = 1;
		end else begin
			assign condOut = 0;
		end
	end

endmodule
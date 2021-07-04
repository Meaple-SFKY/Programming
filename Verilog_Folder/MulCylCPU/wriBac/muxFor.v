module muxForMod (
	input wire wbSig,
	input wire [31:0] lmdOut, aluOOut,
	output reg [31:0] muxForOut
);
	
	always @* begin
		if (wbSig == 0) begin
			assign muxForOut = aluOOut;
		end else begin
			assign muxForOut = lmdOut;
		end
	end

endmodule
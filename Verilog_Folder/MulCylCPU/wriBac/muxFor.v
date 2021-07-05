module muxForMod (
	input wire clk, wbSig,
	input wire [31:0] lmdOut, aluOOut,
	output reg [31:0] muxForOut
);
	
	always @(negedge clk) begin
		if (wbSig == 0) begin
			assign muxForOut = aluOOut;
		end else begin
			assign muxForOut = lmdOut;
		end
	end

endmodule
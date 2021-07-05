module pcMod (
	input wire clk, rst, fecAbl,
	input wire [31:0] pcInp,
	output reg [31:0] pcOut
);
	
	initial begin
		pcOut = 0;
	end

	always @(posedge clk or posedge rst) begin
		if (rst == 1) begin
			assign pcOut = 0;
		end else begin
			if (fecAbl == 1) begin
				assign pcOut = pcInp;
			end
		end
	end

endmodule
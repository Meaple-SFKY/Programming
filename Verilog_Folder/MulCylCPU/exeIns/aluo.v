module aluOMod (
	input wire clk,
	input wire [31:0] aluOut,
	output reg [31:0] aluOOut
);
	
	always @(negedge clk) begin
		assign aluOOut = aluOut;
	end

endmodule
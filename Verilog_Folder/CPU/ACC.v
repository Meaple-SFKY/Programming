module ACC (
	input wire clk, accWR,
	input wire [15 : 0] inData,
	output wire [15 : 0] outData
);

	reg [15 : 0] accData;

	assign outData = accData;

	initial begin
		accData = 0;
	end

	always @(negedge clk) begin
		if (accWR == 1)
			accData = inData;
	end

endmodule
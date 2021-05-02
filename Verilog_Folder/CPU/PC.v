module PC (
	input wire clk, rst, stop, pcWR, ifBan,
	input wire [7 : 0] jump,
	output reg [7 : 0] Addr
);

	initial begin
		Addr = 0;
	end

	always @* begin
		if (stop == 0) begin
			if (rst == 1) begin
				Addr = 0;
			end
		end
	end

	always @(posedge clk) begin
		if (stop == 0) begin
			Addr = Addr + 1;
		end
	end

	always @(negedge clk) begin
		if (stop == 0) begin
			if (pcWR == 1) begin
				if (ifBan == 0) begin
					Addr = jump - 1;
				end else begin
					Addr = Addr + jump - 1;
				end
			end
		end
	end
	
endmodule
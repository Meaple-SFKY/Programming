module uniRegFilMod (
	input wire clk, ifWR, wriReg, rst,
	input wire [4:0] irOutRs, irOutRt, irOutRd,
	input wire [31:0] muxForOut,
	output reg [31:0] regFilOutA, regFilOutB
);
	
	reg [31:0] uniRegFile [0:31];
	integer cou;
	
	always @(posedge clk or posedge rst) begin
		if (rst == 1) begin
			for (cou = 1; cou < 31; cou = cou + 1) begin
				uniRegFile[cou] = 0;
			end
		end else begin
			if (ifWR == 0) begin
				regFilOutA = uniRegFile[irOutRs];
				regFilOutB = uniRegFile[irOutRt];
			end else begin
				if (wriReg == 0) begin
					uniRegFile[irOutRd] = muxForOut;
				end else begin
					uniRegFile[irOutRt] = muxForOut;
				end
			end
		end
	end

endmodule
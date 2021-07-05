module ctrlUniMod (
	input wire clk, rst,
	input wire [5:0] irOutOpe,
	output reg fecAbl, ifWR, wriReg, muxSecSig, muxThiSig, datMemWr, wbSig,
	output reg [5:0] funct
);
	
	integer pos;

	always @(posedge clk or posedge rst) begin
		if (rst == 1) begin
			pos = 0;
		end else begin
			pos = (pos + 1) % 5;
		end
	end

	always @(pos or irOutOpe) begin
		case (pos)
			0: begin
				fecAbl = 1;
				{ifWR, wriReg, muxSecSig, muxThiSig, datMemWr, wbSig} = 6'b000000;
			end

			1: begin
				fecAbl = 0;
				case (irOutOpe)
					
				endcase
			end

			2: begin
				fecAbl = 0;
			end

			3: begin
				fecAbl = 0;
			end

			4: begin
				fecAbl = 0;
			end 

		endcase
	end
endmodule
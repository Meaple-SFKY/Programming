`include "CPU.v"

module CPU_TB;
	reg clk, rst;

	initial begin
		$dumpfile("test.vcd");
		$dumpvars(0, CPU_TB);
		clk = 1;
		rst = 0;

		#1
		rst = ~rst;

		#26
		$stop;
	end

	always @* begin
		if (rst == 1) begin
			#1
			rst = ~rst;
		end
	end

	always #1 begin
		clk = ~clk;
	end

	CPU cpu (
		.clk(clk), .rst(rst)
	);

endmodule
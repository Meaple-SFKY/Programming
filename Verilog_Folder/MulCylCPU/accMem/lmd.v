module lmdMod (
	input wire [31:0] datMemOut,
	output reg [31:0] lmdOut
);
	
	always @* begin
		assign lmdOut = datMemOut;
	end

endmodule
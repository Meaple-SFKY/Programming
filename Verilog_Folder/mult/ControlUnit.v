`timescale 1ns / 1ps

module ControlUnit(
    input clk, rst,
    input zero, sign,//状态位、标志位
    input [5:0] opcode,
    output wire InsMemRW,
    output reg PCWre,//pc使能信号，
    output reg ALUSrcA,//alu的A输入口的选择信号
    output reg ALUSrcB,//alu的B输入口的选择信号
    output reg DBDataSrc,//DBDR输入端的选择信号
    output reg RegWre,//寄存器堆的使能信号
    output reg WrRegDSrc,//寄存器堆的写回数据的选择信号
    output reg mRD,//数据存储器的读控制信号
    output reg mWR,//数据存储器的写控制信号
    output reg IRWre,//IR的使能信号
    output reg ExtSel,//立即数扩展方式选择信号
    output reg [1:0] PCSrc,//pc的指令输入端口选择信号
    output reg [1:0] RegDst,//写入寄存器地址的输入端口选择信号
    output reg [2:0] ALUOp//运算器操作码
    );
    
    reg [2:0] state;//用三位二进制数来表示CPU运行中的8个状态
    assign InsMemRW = 1;    // 设置指令存储器为只读
    
    /* 状态转移 */
    always @(posedge clk or negedge rst) begin
        if(rst==0) begin//复位信号，状态置零
            state <= 3'b000;
            PCWre <= 1;//pc使能信号
            IRWre <= 1;//ir使能信号
        end
        else begin
            case(state)//判断当前状态
                3'b000: state <= 3'b001;//取址状态直接转译码状态
                3'b001: begin//译码状态
                        if(opcode==6'b110100 || opcode==6'b110101 || opcode==6'b110110) state <= 3'b101;//若为beq、bne、bltz，转第二类执行状态
                        else if(opcode==6'b110000 || opcode==6'b110001) state <= 3'b010;//若为sw、lw，转第三类执行状态
                        else if(opcode==6'b111000 || opcode==6'b111001 || opcode==6'b111010 || opcode==6'b111111)//若为j、jal、jr、halt，转取址状态
                            state <= 3'b000;
                        else state <= 3'b110;//其余正常执行，转第一类执行状态
                    end
                3'b110: state <= 3'b111;//第一类执行状态转第一类写回状态
                3'b010: state <= 3'b011;//第三类执行状态转存储状态
                3'b011: begin//存储状态
                        if(opcode==6'b110001) state <= 3'b100;//若为lw，转写回状态
                        else state <= 3'b000;//sw转取址状态
                    end
                3'b111, 3'b101, 3'b100: state <= 3'b000;//第一类写回状态、第二类执行状态、第三类写回状态，转取址状态
            endcase
        end
    end
    
    /* 输出函数 */
    always @(state or opcode or zero or sign) begin
        case(opcode)//判断操作码类型
            6'b000000: begin  // add
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_00_10_000;
                case(state)//ir使能信号、数据存储器使能信号、寄存器堆写使能信号
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;//取址
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;//译码
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;//执行
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;//写回
                endcase
            end
            6'b000001: begin  // sub
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_00_10_001;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b000010: begin  // addiu
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010101_00_01_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b010000: begin  // and
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_00_10_100;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b010001: begin  // andi
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010100_00_01_100;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b010010: begin  // ori
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010100_00_01_011;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b010011: begin  // xori
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010100_00_01_111;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b011000: begin  // sll
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b100100_00_10_010;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
           end
            6'b100110: begin  // slti
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010101_00_01_110;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b100111: begin  // slt
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_00_10_110;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b110: {IRWre, mWR, RegWre} = 4'b100;
                    3'b111: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b110000: begin  // sw
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b010101_00_00_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b010: {IRWre, mWR, RegWre} = 4'b100;
                    3'b011: {IRWre, mWR, RegWre} = 4'b110;
                endcase
            end
            6'b110001: begin  // lw
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b011111_00_01_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                    3'b010: {IRWre, mWR, RegWre} = 4'b100;
                    3'b011: {IRWre, mWR, RegWre} = 4'b100;
                    3'b100: {IRWre, mWR, RegWre} = 4'b101;
                endcase
            end
            6'b110100: begin  // beq
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, RegDst[1:0], ALUOp[2:0]} <= 11'b000101_00_001;
                PCSrc[1:0] <= (zero==1) ? 2'b01 : 2'b00;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    default: {IRWre, mWR, RegWre} = 4'b100;
                endcase
            end
            6'b110101: begin  // bne
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, RegDst[1:0], ALUOp[2:0]} <= 11'b000101_00_001;
                PCSrc[1:0] <= (zero==0) ? 2'b01 : 2'b00;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    default: {IRWre, mWR, RegWre} = 4'b100;
                endcase
            end
            6'b110110: begin  // bltz
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, RegDst[1:0], ALUOp[2:0]} <= 11'b000101_00_000;
                PCSrc[1:0] <= (sign==1) ? 2'b01 : 2'b00;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    default: {IRWre, mWR, RegWre} = 4'b100;
                endcase
            end
            6'b111000: begin  // j
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_11_00_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                endcase
            end
            6'b111001: begin  // jr
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_10_00_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b100;
                endcase
            end
            6'b111010: begin  // jal
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000000_11_00_000;
                case(state)
                    3'b000: {IRWre, mWR, RegWre} = 4'b100;
                    3'b001: {IRWre, mWR, RegWre} = 4'b101;  // jal在ID阶段（001）写寄存器
                endcase
            end
            6'b111111: begin  // halt
                {ALUSrcA, ALUSrcB, DBDataSrc, WrRegDSrc, mRD, ExtSel, PCSrc[1:0], RegDst[1:0], ALUOp[2:0]} <= 13'b000100_00_00_000;
                {IRWre, mWR, RegWre} = 4'b100;
            end
        endcase
    end
    
    always @(negedge clk) begin
        case(state)
            3'b111, 3'b101, 3'b100: PCWre <= 1;//写回1、执行2、写回3，pc使能信号置1
            3'b011: PCWre <= (opcode==6'b110000 ? 1 : 0);   //sw指令，pc使能信号置1
            3'b001: PCWre <= (opcode==6'b111000||opcode==6'b111001||opcode==6'b111010 ? 1 : 0);  //j, jr, jal，pc使能信号置1
            default: PCWre <= 0;//否则置0
        endcase
    end
    
endmodule

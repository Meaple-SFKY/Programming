	.text
	.globl _test
_test:
LFB0:
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	cmpq	$-3, %rdi
	jge	L2
	cmpq	%rdx, %rsi
	jge	L3
	movq	%rdi, %rax
	imulq	%rsi, %rax
	ret
L3:
	movq	%rsi, %rax
	imulq	%rdx, %rax
	ret
L2:
	cmpq	$2, %rdi
	jle	L1
	movq	%rdi, %rax
	imulq	%rdx, %rax
L1:
	ret
LFE0:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols

	.file	"ns.c"
	.text
	.section	.rodata
.LC0:
	.string	"%u%u"
.LC1:
	.string	"ns.c"
.LC2:
	.string	"res==2"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	cmpl	$2, -12(%rbp)
	je	.L2
	leaq	__PRETTY_FUNCTION__.0(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	__assert_fail@PLT
.L2:
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	print_conv
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
.LC3:
	.string	"%u"
	.text
	.globl	print_conv
	.type	print_conv, @function
print_conv:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movl	%edi, -164(%rbp)
	movl	%esi, -168(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-144(%rbp), %rdx
	movl	$0, %eax
	movl	$16, %ecx
	movq	%rdx, %rdi
	rep stosq
	movl	$0, -148(%rbp)
	jmp	.L6
.L7:
	movl	-164(%rbp), %eax
	movl	$0, %edx
	divl	-168(%rbp)
	movl	-148(%rbp), %eax
	cltq
	movl	%edx, -144(%rbp,%rax,4)
	movl	-164(%rbp), %eax
	movl	$0, %edx
	divl	-168(%rbp)
	movl	%eax, -164(%rbp)
	addl	$1, -148(%rbp)
.L6:
	cmpl	$0, -164(%rbp)
	jne	.L7
	subl	$1, -148(%rbp)
	jmp	.L8
.L9:
	movl	-148(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -148(%rbp)
	cltq
	movl	-144(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L8:
	cmpl	$0, -148(%rbp)
	jns	.L9
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	print_conv, .-print_conv
	.section	.rodata
	.type	__PRETTY_FUNCTION__.0, @object
	.size	__PRETTY_FUNCTION__.0, 5
__PRETTY_FUNCTION__.0:
	.string	"main"
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

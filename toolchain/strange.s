	.file	"strange.c"
	.intel_syntax noprefix
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB23:
	.cfi_startproc
	endbr64
	mov	rax, rdi
	mov	DWORD PTR [rdi], 0
	mov	DWORD PTR 4[rdi], 1
	mov	DWORD PTR 8[rdi], 2
	mov	DWORD PTR 12[rdi], 3
	mov	DWORD PTR 16[rdi], 4
	mov	DWORD PTR 20[rdi], 5
	mov	DWORD PTR 24[rdi], 0
	mov	DWORD PTR 28[rdi], 0
	mov	DWORD PTR 32[rdi], 0
	mov	DWORD PTR 36[rdi], 0
	ret
	.cfi_endproc
.LFE23:
	.size	foo, .-foo
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	sub	rsp, 56
	.cfi_def_cfa_offset 64
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 40[rsp], rax
	xor	eax, eax
	mov	rdi, rsp
	call	foo
	mov	edx, DWORD PTR 12[rsp]
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	rax, QWORD PTR 40[rsp]
	sub	rax, QWORD PTR fs:40
	jne	.L5
	mov	eax, 0
	add	rsp, 56
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
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

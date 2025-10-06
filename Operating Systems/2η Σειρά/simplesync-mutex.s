	.file	"simplesync.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"About to increase variable %d times\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Done increasing variable.\n"
	.text
	.p2align 4
	.globl	increase_fn
	.type	increase_fn, @function
increase_fn:
.LFB52:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	stderr(%rip), %rdi
	movl	$1000000, %ecx
	leaq	.LC0(%rip), %rdx
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk@PLT
	movl	$1000000, %edx
	.p2align 4,,10
	.p2align 3
.L2:
	movl	(%rbx), %eax
	addl	$1, %eax
	movl	%eax, (%rbx)
	subl	$1, %edx
	jne	.L2
	movq	stderr(%rip), %rcx
	movl	$26, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rdi
	call	fwrite@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE52:
	.size	increase_fn, .-increase_fn
	.section	.rodata.str1.8
	.align 8
.LC2:
	.string	"About to decrease variable %d times\n"
	.section	.rodata.str1.1
.LC3:
	.string	"Done decreasing variable.\n"
	.text
	.p2align 4
	.globl	decrease_fn
	.type	decrease_fn, @function
decrease_fn:
.LFB53:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	stderr(%rip), %rdi
	movl	$1000000, %ecx
	leaq	.LC2(%rip), %rdx
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk@PLT
	movl	$1000000, %edx
	.p2align 4,,10
	.p2align 3
.L7:
	movl	(%rbx), %eax
	subl	$1, %eax
	movl	%eax, (%rbx)
	subl	$1, %edx
	jne	.L7
	movq	stderr(%rip), %rcx
	movl	$26, %edx
	movl	$1, %esi
	leaq	.LC3(%rip), %rdi
	call	fwrite@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE53:
	.size	decrease_fn, .-decrease_fn
	.section	.rodata.str1.1
.LC4:
	.string	""
.LC5:
	.string	"NOT "
.LC6:
	.string	"pthread_create"
.LC7:
	.string	"pthread_join"
.LC8:
	.string	"%sOK, val = %d.\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB9:
	.section	.text.startup,"ax",@progbits
.LHOTB9:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB54:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%esi, %esi
	leaq	increase_fn(%rip), %rdx
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	4(%rsp), %rbp
	leaq	8(%rsp), %rdi
	movl	$0, 4(%rsp)
	movq	%rbp, %rcx
	call	pthread_create@PLT
	testl	%eax, %eax
	jne	.L24
	leaq	16(%rsp), %rdi
	movq	%rbp, %rcx
	leaq	decrease_fn(%rip), %rdx
	xorl	%esi, %esi
	call	pthread_create@PLT
	movl	%eax, %ebx
	testl	%eax, %eax
	jne	.L25
	movq	8(%rsp), %rdi
	xorl	%esi, %esi
	call	pthread_join@PLT
	movl	%eax, %ebx
	testl	%eax, %eax
	jne	.L26
.L13:
	movq	16(%rsp), %rdi
	xorl	%esi, %esi
	call	pthread_join@PLT
	movl	%eax, %ebx
	testl	%eax, %eax
	jne	.L27
.L14:
	movl	4(%rsp), %ecx
	xorl	%ebx, %ebx
	leaq	.LC4(%rip), %rax
	leaq	.LC5(%rip), %rdx
	leaq	.LC8(%rip), %rsi
	movl	$1, %edi
	testl	%ecx, %ecx
	cmove	%rax, %rdx
	sete	%bl
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L29
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L29:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.type	main.cold, @function
main.cold:
.LFSB54:
.L27:
	.cfi_def_cfa_offset 64
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	call	__errno_location@PLT
	leaq	.LC7(%rip), %rdi
	movl	%ebx, (%rax)
	call	perror@PLT
	jmp	.L14
.L26:
	call	__errno_location@PLT
	leaq	.LC7(%rip), %rdi
	movl	%ebx, (%rax)
	call	perror@PLT
	jmp	.L13
.L25:
	call	__errno_location@PLT
	leaq	.LC6(%rip), %rdi
	movl	%ebx, (%rax)
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L24:
	movl	%eax, %ebx
	call	__errno_location@PLT
	leaq	.LC6(%rip), %rdi
	movl	%ebx, (%rax)
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE54:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE9:
	.section	.text.startup
.LHOTE9:
	.globl	mutex
	.bss
	.align 32
	.type	mutex, @object
	.size	mutex, 40
mutex:
	.zero	40
	.ident	"GCC: (Ubuntu 13.2.0-4ubuntu3) 13.2.0"
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

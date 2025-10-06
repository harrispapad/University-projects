	.file	"pthread-test.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Thread %d of %d. START.\n"
.LC1:
	.string	"Thread %d of %d. END.\n"
	.text
	.p2align 4
	.globl	thread_start_fn
	.type	thread_start_fn, @function
thread_start_fn:
.LFB55:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movl	32(%rdi), %ecx
	leaq	.LC0(%rip), %rdx
	movl	36(%rdi), %r8d
	movq	stderr(%rip), %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk@PLT
	movl	32(%rbx), %edi
	movl	16(%rbx), %ecx
	cmpl	%ecx, %edi
	jge	.L2
	movslq	36(%rbx), %rsi
	movq	8(%rbx), %rdx
	movslq	%edi, %rax
	movq	%rsi, %r8
	.p2align 4,,10
	.p2align 3
.L3:
	movsd	(%rdx,%rax,8), %xmm0
	mulsd	24(%rbx), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	addq	%rsi, %rax
	cmpl	%eax, %ecx
	jg	.L3
.L4:
	movl	%edi, %ecx
	movq	stderr(%rip), %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rdx
	call	__fprintf_chk@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L2:
	.cfi_restore_state
	movl	36(%rbx), %r8d
	jmp	.L4
	.cfi_endproc
.LFE55:
	.size	thread_start_fn, .-thread_start_fn
	.p2align 4
	.globl	safe_atoi
	.type	safe_atoi, @function
safe_atoi:
.LFB52:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$10, %edx
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rsi
	call	strtol@PLT
	movq	(%rsp), %rdx
	cmpq	%rbx, %rdx
	je	.L12
	cmpb	$0, (%rdx)
	jne	.L12
	movl	%eax, 0(%rbp)
	xorl	%eax, %eax
.L8:
	movq	8(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L14
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L8
.L14:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE52:
	.size	safe_atoi, .-safe_atoi
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Out of memory, failed to allocate %zd bytes\n"
	.text
	.p2align 4
	.globl	safe_malloc
	.type	safe_malloc, @function
safe_malloc:
.LFB53:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	call	malloc@PLT
	testq	%rax, %rax
	je	.L18
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	movq	stderr(%rip), %rdi
	movq	%rbx, %rcx
	movl	$1, %esi
	leaq	.LC2(%rip), %rdx
	call	__fprintf_chk@PLT
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE53:
	.size	safe_malloc, .-safe_malloc
	.section	.rodata.str1.8
	.align 8
.LC3:
	.string	"Usage: %s thread_count array_size\n\nExactly two argument required:\n    thread_count: The number of threads to create.\n    array_size: The size of the array to run with.\n"
	.text
	.p2align 4
	.globl	usage
	.type	usage, @function
usage:
.LFB54:
	.cfi_startproc
	endbr64
	pushq	%rax
	.cfi_def_cfa_offset 16
	popq	%rax
	.cfi_def_cfa_offset 8
	leaq	.LC3(%rip), %rdx
	movl	$1, %esi
	xorl	%eax, %eax
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	%rdi, %rcx
	movq	stderr(%rip), %rdi
	call	__fprintf_chk@PLT
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE54:
	.size	usage, .-usage
	.section	.rodata.str1.8
	.align 8
.LC4:
	.string	"`%s' is not valid for `thread_count'\n"
	.align 8
.LC5:
	.string	"`%s' is not valid for `array_size'\n"
	.section	.rodata.str1.1
.LC8:
	.string	"pthread_create"
.LC9:
	.string	"pthread_join"
	.section	.rodata.str1.8
	.align 8
.LC11:
	.string	"Internal error: arr[%d] = %f, not %f\n"
	.section	.rodata.str1.1
.LC12:
	.string	"OK."
	.section	.text.unlikely,"ax",@progbits
.LCOLDB13:
	.section	.text.startup,"ax",@progbits
.LHOTB13:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB56:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	cmpl	$3, %edi
	jne	.L51
	movq	8(%rbx), %rdi
	leaq	36(%rsp), %rsi
	call	safe_atoi
	testl	%eax, %eax
	js	.L23
	movl	36(%rsp), %eax
	movl	%eax, 12(%rsp)
	testl	%eax, %eax
	jle	.L23
	movq	16(%rbx), %rdi
	leaq	32(%rsp), %rsi
	call	safe_atoi
	testl	%eax, %eax
	js	.L25
	movl	32(%rsp), %r14d
	testl	%r14d, %r14d
	jle	.L25
	movslq	%r14d, %r12
	leaq	0(,%r12,8), %r13
	movq	%r13, %rdi
	call	safe_malloc
	movsd	.LC6(%rip), %xmm0
	leaq	0(%r13,%rax), %rdx
	andl	$8, %r13d
	movq	%rax, %rbx
	je	.L27
	movsd	%xmm0, (%rax)
	leaq	8(%rax), %rax
	cmpq	%rdx, %rax
	je	.L48
	.p2align 4,,10
	.p2align 3
.L27:
	movsd	%xmm0, (%rax)
	addq	$16, %rax
	movsd	%xmm0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L27
.L48:
	movslq	12(%rsp), %rax
	xorl	%r13d, %r13d
	leaq	(%rax,%rax,4), %rax
	salq	$3, %rax
	movq	%rax, %rdi
	movq	%rax, 16(%rsp)
	call	safe_malloc
	movq	%rax, 24(%rsp)
	movq	%rax, %rbp
	movq	%rax, %r15
	.p2align 4,,10
	.p2align 3
.L29:
	movq	.LC7(%rip), %rax
	movq	%rbx, 8(%rbp)
	xorl	%esi, %esi
	movq	%rbp, %rcx
	movd	12(%rsp), %xmm2
	movd	%r13d, %xmm0
	movl	%r14d, 16(%rbp)
	movq	%rbp, %rdi
	movq	%rax, 24(%rbp)
	leaq	thread_start_fn(%rip), %rdx
	punpckldq	%xmm2, %xmm0
	movq	%xmm0, 32(%rbp)
	call	pthread_create@PLT
	testl	%eax, %eax
	jne	.L45
	addl	$1, %r13d
	addq	$40, %rbp
	cmpl	%r13d, 12(%rsp)
	jne	.L29
	movq	24(%rsp), %r13
	movq	16(%rsp), %rax
	addq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L31:
	movq	(%r15), %rdi
	xorl	%esi, %esi
	call	pthread_join@PLT
	movl	%eax, %ebp
	testl	%eax, %eax
	jne	.L46
	addq	$40, %r15
	cmpq	%r15, %r13
	jne	.L31
	movsd	.LC10(%rip), %xmm1
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L34:
	movsd	(%rbx,%rax,8), %xmm0
	ucomisd	%xmm1, %xmm0
	jp	.L36
	jne	.L36
	addq	$1, %rax
	cmpq	%rax, %r12
	jne	.L34
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	movq	40(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L52
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L36:
	.cfi_restore_state
	movq	stderr(%rip), %rdi
	movl	%eax, %ecx
	movl	$1, %esi
	leaq	.LC11(%rip), %rdx
	movl	$2, %eax
	call	__fprintf_chk@PLT
	movl	$1, %edi
	call	exit@PLT
.L23:
	movq	8(%rbx), %rcx
	leaq	.LC4(%rip), %rdx
.L50:
	movq	stderr(%rip), %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk@PLT
	movl	$1, %edi
	call	exit@PLT
.L51:
	movq	(%rsi), %rdi
	call	usage
.L25:
	movq	16(%rbx), %rcx
	leaq	.LC5(%rip), %rdx
	jmp	.L50
.L52:
	call	__stack_chk_fail@PLT
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.type	main.cold, @function
main.cold:
.LFSB56:
.L46:
	.cfi_def_cfa_offset 112
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	call	__errno_location@PLT
	leaq	.LC9(%rip), %rdi
	movl	%ebp, (%rax)
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L45:
	movl	%eax, 12(%rsp)
	call	__errno_location@PLT
	movl	12(%rsp), %edx
	leaq	.LC8(%rip), %rdi
	movl	%edx, (%rax)
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE56:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE13:
	.section	.text.startup
.LHOTE13:
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	0
	.long	1073217536
	.align 8
.LC7:
	.long	0
	.long	1074790400
	.align 8
.LC10:
	.long	0
	.long	1075314688
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

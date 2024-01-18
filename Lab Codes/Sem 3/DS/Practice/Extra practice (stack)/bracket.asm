	.file	"bracket.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Overflow!\12\0"
	.text
	.globl	push
	.def	push;	.scl	2;	.type	32;	.endef
	.seh_proc	push
push:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, %eax
	movb	%al, 32(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movl	24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, %edx
	jne	.L6
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L8
.L6:
	movq	16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %ecx
	movq	16(%rbp), %rax
	movl	%ecx, (%rax)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cltq
	addq	%rax, %rdx
	movzbl	32(%rbp), %eax
	movb	%al, (%rdx)
.L8:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "Underflow!\12\0"
	.text
	.globl	pop
	.def	pop;	.scl	2;	.type	32;	.endef
	.seh_proc	pop
pop:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$-1, %eax
	jne	.L10
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L9
.L10:
	movq	16(%rbp), %rax
	movq	8(%rax), %r8
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	leal	-1(%rax), %ecx
	movq	16(%rbp), %rdx
	movl	%ecx, (%rdx)
	cltq
	addq	%r8, %rax
	movzbl	(%rax), %eax
.L9:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "%c\12\0"
	.text
	.globl	display
	.def	display;	.scl	2;	.type	32;	.endef
	.seh_proc	display
display:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L14
.L15:
	movq	16(%rbp), %rax
	movq	8(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L14:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L15
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	isOpenBracket
	.def	isOpenBracket;	.scl	2;	.type	32;	.endef
	.seh_proc	isOpenBracket
isOpenBracket:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	cmpb	$40, 16(%rbp)
	je	.L17
	cmpb	$123, 16(%rbp)
	je	.L17
	cmpb	$91, 16(%rbp)
	jne	.L18
.L17:
	movl	$1, %eax
	jmp	.L19
.L18:
	movl	$0, %eax
.L19:
	popq	%rbp
	ret
	.seh_endproc
	.globl	isClosedBracket
	.def	isClosedBracket;	.scl	2;	.type	32;	.endef
	.seh_proc	isClosedBracket
isClosedBracket:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	cmpb	$41, 16(%rbp)
	je	.L21
	cmpb	$125, 16(%rbp)
	je	.L21
	cmpb	$93, 16(%rbp)
	jne	.L22
.L21:
	movl	$1, %eax
	jmp	.L23
.L22:
	movl	$0, %eax
.L23:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "invalid!\12\0"
.LC4:
	.ascii "Invalid!\12\0"
.LC5:
	.ascii "Valid!\12\0"
	.text
	.globl	isValid
	.def	isValid;	.scl	2;	.type	32;	.endef
	.seh_proc	isValid
isValid:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	24(%rbp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$31, %eax
	addl	%eax, %edx
	andl	$1, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$1, %eax
	jne	.L25
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L24
.L25:
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L27
.L33:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	isOpenBracket
	testl	%eax, %eax
	je	.L28
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movl	24(%rbp), %edx
	movq	16(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	push
	jmp	.L29
.L28:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	isClosedBracket
	testl	%eax, %eax
	je	.L29
	movl	24(%rbp), %edx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	pop
	movb	%al, -9(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$93, %al
	jne	.L30
	cmpb	$91, -9(%rbp)
	jne	.L31
.L30:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$125, %al
	jne	.L32
	cmpb	$123, -9(%rbp)
	jne	.L31
.L32:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$41, %al
	jne	.L29
	cmpb	$40, -9(%rbp)
	je	.L29
.L31:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L24
.L29:
	addl	$1, -4(%rbp)
.L27:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L33
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	nop
.L24:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC6:
	.ascii "Enter size of array:- \0"
.LC7:
	.ascii "%d\0"
.LC8:
	.ascii "Enter elements:- \12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	call	__main
	movl	$-1, -32(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	-36(%rbp), %eax
	cltq
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -8(%rbp)
	movl	-36(%rbp), %eax
	cltq
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getchar
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	gets
	movl	-36(%rbp), %edx
	movq	-8(%rbp), %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	isValid
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 12.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	gets;	.scl	2;	.type	32;	.endef

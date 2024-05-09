.data
		integer_format:	.asciz,	"%ld\n"
.global	main
		str0:	.string,	"__main__"
.text
main:
		pushq	%rbp
		movq	%rsp,	%rbp
		pushq	%rbx
		pushq	%rdi
		pushq	%rsi
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		sub	$48,	%rsp
		pushq	%rax
		pushq	%rcx
		pushq	%rdx
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	$24
		call	allocmem
		add	$8,	%rsp
		mov	%rax,	-64(%rbp)
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		popq	%rdx
		popq	%rcx
		popq	%rax
		movq	$1,	%rax
		movq	-64(%rbp),	%rdx
		movq	%rax,	(%rdx)
		movq	-64(%rbp),	%rdx
		add	$8,	%rdx
		movq	%rdx,	-72(%rbp)
		movq	$2,	%rax
		movq	-72(%rbp),	%rdx
		movq	%rax,	(%rdx)
		movq	-64(%rbp),	%rdx
		add	$16,	%rdx
		movq	%rdx,	-80(%rbp)
		movq	$4,	%rax
		movq	-80(%rbp),	%rdx
		movq	%rax,	(%rdx)
		movq	-64(%rbp),	%rdx
		movq	%rdx,	-88(%rbp)
		movq	-88(%rbp),	%rdx
		add	$16,	%rdx
		movq	%rdx,	-96(%rbp)
		movq	-96(%rbp),	%rdx
		movq	(%rdx),	%rdx
		movq	%rdx,	-104(%rbp)
		pushq	%rax
		pushq	%rcx
		pushq	%rdx
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	-104(%rbp)
		call	print
		add	$8,	%rsp
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		popq	%rdx
		popq	%rcx
		popq	%rax
		movq	$60,	%rax
		xor	%rdi,	%rdi
		syscall
print:
    pushq	%rbp
    mov	%rsp,	%rbp
    pushq	%rbx
    pushq	%rdi
    pushq	%rsi
    pushq	%r12
    pushq	%r13
    pushq	%r14
    pushq	%r15

    testq $15, %rsp
    jz is_print_aligned

    pushq $0                 # align to 16 bytes

    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi      
    xor %rax, %rax          
    call printf

    add $8, %rsp
    jmp print_done

is_print_aligned:

    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi          
    xor %rax, %rax         
    call printf
    
print_done: 

    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rsi
    popq %rdi
    popq %rbx
    popq %rbp

    ret
allocmem:
    pushq	%rbp
    mov	%rsp,	%rbp
    pushq	%rbx
    pushq	%rdi
    pushq	%rsi
    pushq	%r12
    pushq	%r13
    pushq	%r14
    pushq	%r15

    testq $15, %rsp
    jz is_mem_aligned

    pushq $0                 # align to 16 bytes
    
    movq 16(%rbp), %rdi
    call malloc

    add $8, %rsp             # remove padding

    jmp mem_done

is_mem_aligned:

    movq 16(%rbp), %rdi
    call malloc
   
mem_done: 

    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rsi
    popq %rdi
    popq %rbx
    popq %rbp

    ret

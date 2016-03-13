.section .data
data_items:
	.long 3,67,64,222,45,75,54,3,44,33,22,11,66,255

.section .text

.globl _start
_start:
	movl $0, %edi
	movl data_items(,%edi,4), %eax
	movl %eax, %ebx

start_loop:
	cmpl $255, %eax
	je loop_exit
	incl %edi
	movl data_items(,%edi,4), %eax
	cmpl %ebx, %eax
	jge start_loop

	movl %eax, %ebx
	jmp start_loop

loop_exit:
	movl $1, %eax
	int $0x80

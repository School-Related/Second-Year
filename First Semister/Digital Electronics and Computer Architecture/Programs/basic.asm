; Define variables in the data section
SECTION .DATA
	hello:     dq 'Hello',5
	helloLen:  equ $-hello

; Code goes in the text section
section .TEXT
	GLOBAL _start 

_start:
; writing something 
mov rax, 1
mov rdi, 1
mov rsi, hello
mov rdx, helloLen
syscall

; reading something 
mov rax, 0; function number for reading or inputting data
mov rdi, 0; file descriptor id for standard input device. keyboard
mov rsi, hello; starting address of the variable to be read
mov rdx, 8 ; maximum bytes to be read
syscall;
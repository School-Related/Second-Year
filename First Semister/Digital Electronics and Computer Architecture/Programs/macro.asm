; Define variables in the data section
section .data
	hello db 'Hello People of DECA, Enter your name!',10
	helloLen  equ $-hello
; Code goes in the text section
section .bss
name resb 30

section .text
	GLOBAL _start 

_start:
; writing something 
mov rax, 1
mov rdi, 1
mov rsi, hello
mov rdx, helloLen

syscall

mov rax, 0; function number for reading or inputting data
mov rdi, 0; file descriptor id for standard input device. keyboard
mov rsi, name; starting address of the variable to be read
mov rdx, 30 ; maximum bytes to be read
syscall;

mov rax, 1
mov rdi, 1
mov rsi, name
mov rdx, 30
syscall;

mov rax, 60
mov rdi, 0
syscall

; reading something 
; mov rax, 0; function number for reading or inputting data
; mov rdi, 0; file descriptor id for standard input device. keyboard
; mov rsi, hello; starting address of the variable to be read
; mov rdx, 8 ; maximum bytes to be read
; syscall;
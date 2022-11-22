; display 2 digit hexx numbers
section .data
    msg db "Addition of 2 numbers ", 10
    msglen equ $-msg
    num1 db 3AH ; the number to be printed. h is for hex
    num2 db 22H ; the number to be printed. h is for hex

section .bss
; temp data assignment
    sum resb 1
    temp resb 1

section .text
global _start

_start:
    ; printing the first message
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msglen
    syscall

    ; assign one byte of num1 to al
    mov al, byte[num1]
    add al, byte[num2]
    ;assign the value of al to sum
    ;mov byte[sum], al
    ;assign 2 to bp
    mov bp, 2; bp = 2
    ; shift all binary bits 4 times to right, this flips the nibbles
    ; so rn its 0010 0011 after flipping it becomes 0011 0010

up:rol al, 4
    ; assign al to bl
    mov bl, al; al = 32H
    ; and with 0FH, so 0000 1111 anded with 0000 0010 so youll end up with the 0010
    and al, 0FH ; al = 02H at this point
    ; this would trigger some flag
    cmp al, 09
    ; goto down label if the above cmp statement gives less than or equal to
    jbe down
    add al, 07H

down: Add al, 30H; al = 32H
    mov byte[temp], al
    mov rax, 1
    mov rdi, 1
    mov rsi, temp
    mov rdx, 1
    syscall
    mov al, bl ; bl = 23H
    dec bp ; this is the loop register which we decrement if its 0 then we stop the loop
    jnz up; now go to up again, and this time you would use bls value to al coz you would rotate it again. 

mov rax, 60
mov rdi, 0
syscall

section .data
    ;something db "Hello World!", 0xa
    ;something_len equ $ - something
    num1 db 2H ; the number to be printed. h is for hex
    num2 db 2H ; the number to be printed. h is for hex


section .bss
    something resb 100; the string to be printed
    something_len resb 1; the length of the string
    sum resb 1; the sum of the numbers
    temp resb 1; the temporary variable

section .text


global _start

%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro read 2
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro



    _start: 
        read something, something_len
        ; write(1, something, something_len)
        print something , something_len

        mov al, byte[num1] ; load the number into al
        add al, byte[num2] ; add the number to al
        mov bp, 2;

    up: rol al, 4 ; rotate the number left 4 bits
        mov bl, al; move the number into bl
        and al, 0fh ; mask the number to get the first 4 bits

        cmp al, 9 ; compare the number to 9
        jbe down ; if the number is less than or equal to 9, jump to down

        add al, 7 ; if the number is greater than 9, add 7 to it

    down: add al, 30h ; add 30h to the number to get the ascii value
        mov byte[temp], al ; move the number into temp

        print temp , 1 ; print the number

        mov al, bl ; move the number back into al
        dec bp ; decrement bp
        jnz up ; if bp is not 0, jump to up

        mov rax, 60 ; exit
        mov rdi, 0 ; exit code
        syscall

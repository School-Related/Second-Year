```Assembly
section .data (declare data segment)
; initialized variable declaraation
section .BSS (declare blockk started by segment sort of extra data segment)
; uninitialized variable declaration
section .Text (declare code segment)
Global _start(Entry point of the program)
_start:
;program code goes here.
```

Assembly uses ; to give comments.

# Data section

lets talk about the data section

syntax to make a variable:
var_name data_type variable value
eg `A DB 50`

data types are like this:
DB - Declare/ Define Byte (8 bit)
DW - Declare/ Define Word (16 bit)
DD - Declare/ Define Double Word (32 bit)
DQ - Declare/ Define Quad Word (64 bit)

you can do this.

```
msg db 10, "The sum of the array elements is: "
; the 10 is for \n
msg_len equ $-msg
; this calculates length of msg and assigns to var msg_len
```

EQU - directive assigns right side value to the left side variable.
$ is the current address of prompt or pointer.
10 - new line ascii value in decimal (you can use 0Ah in hex)
msg - starting address of the variale msg

in the above example:
let starting address of the messge be 100 say, then $= 129 (including everything inside the quotes)
$-msg = 129 - 100 = 29
so msg_len would then be equal to 29.

# Making uninitialized variables

syntaX: var_name RES memory_type Memory_size
eg: `A RESB 50`
just allocate 50 bytes to it.

RES- Reserve memory types:
RESB, RESW, RESD and stuff.

# Section .TXT

section .TXT code of the program is where you write instructions. you gotta always start
`global _start(entry point)`
`_start: `

it can have microprocessor instructions
it can write and read system calls.
it has to end with exit statements.

# System calls:

display_variable_name contents of specified variable length on monitor

To write something

```
mov rax 1 // coz this is the main register for printing
mov rdi, 1 // file descriptor id for stadard output devie which is the monitor.
mov rsi msg // starting address of the string to be displayed.
mov rdx //msglen, number of lengths to be displayedd.
syscall // inbuilt function
```

To read someting

```
; reading something
mov rax, 0; function number for reading or inputting data
mov rdi, 0; file descriptor id for standard input device. keyboard
mov rsi, hello; starting address of the variable to be read
mov rdx, 8 ; maximum bytes to be read
syscall;
```

# macro syntax
```assembly
%macro macr-name no_of_parameters
    %1 ; first parameters
    %2 ; second parameters
    %3 ; third parameters and so on 
%endmacro
```

callling it
macro_name firstparameters, second_parameter, ;third parameter
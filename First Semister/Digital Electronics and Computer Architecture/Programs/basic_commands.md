# compiling assemble
command to assemble it:
` nasm -f elf64 first.asm`
-f is for file format. default output is binary, and object file is created. 
you then need to link it. 
ld is the gnu linker. you gotta link it to basic libarries. 
`ld -o <output file name>  objfile.o`
this creates the object file.

To Execute, just do 
`./filename` 
section .data
    hello db 'Hello, Holberton',0xA

section .text
    global main

main:
    ; write message to stdout
    mov eax, 1        ; system call number for write
    mov edi, 1        ; file descriptor for stdout
    mov rsi, hello    ; address of the message
    mov edx, 18       ; length of the message
    syscall

    ; exit the program
    mov eax, 60       ; system call number for exit
    xor edi, edi      ; exit status 0
    syscall


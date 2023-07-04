section .data
    format db 'Hello, Holberton', 0xA, 0

section .text
    global main

extern printf

main:
    ; call printf to print the string
    push format
    call printf
    add esp, 4

    ; return 0
    xor eax, eax
    ret


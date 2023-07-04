section .data
    message db 'Hello, Holberton', 0xA, 0

section .text
    global main

extern printf

main:
    ; push the address of the format string onto the stack
    push message
    ; call printf
    call printf
    ; clean up the stack
    add esp, 4

    ; return 0
    mov eax, 0
    ret


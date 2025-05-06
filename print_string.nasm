print_string:
    push rbp
    mov rsi, rdi
    call puts
    pop rbp
    ret

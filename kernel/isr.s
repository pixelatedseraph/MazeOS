.code32

.global isr0
.global isr13
.global isr8

.extern divide_handler
.extern gpf_handler

isr0:
    pusha

    call divide_handler

    popa
    iret


isr8:
1:
    cli
    hlt
    jmp 1b

isr13:
    pusha

    movl 36(%esp), %eax
    pushl %eax

    call gpf_handler

    addl $4, %esp
    popa

    addl $4, %esp      # remove CPU error code
    iret
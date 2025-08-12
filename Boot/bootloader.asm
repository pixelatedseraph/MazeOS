[BITS 16]  ; 16 bit real mode
[ORG 0x7C00] ; tells the bios to find bootloader at this address

start:
    ; set video mode to 80 *25 text mode
    mov ax, 0x0003
    int 0x10

    mov si, msg ; si points to the string

print:
    lodsb ; loads the char from si to al and increments it by si = si + 1
    cmp al, 0 ; check if the string terminated
    je done
    mov ah, 0x0E ; bios teletype function , a function to print the letter
    int 0x10
    jmp print

done:
    jmp $
msg db "Welcome to CortusBootLoader!", 0
;boot sector must be exactly 512 bytes ,ending with 0xAA55
times 510-($-$$) db 0
dw 0xAA55
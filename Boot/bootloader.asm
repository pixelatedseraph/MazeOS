[BITS 16] ; 16 bit mode 
[ORG 0x7C00] ; bios finds cortus here

start:
        ; set video mode 
        mov ax, 0x003 ; set 80 * 25 text mode , a function value provided by bios
        int 0x10      ;bios interrupt to display

        ;clear screen 
        mov ah, 0x06 ; scroll up fucntion from bios
        mov al, 0    ;scroll entire window
        mov bh, 0x07 ; text attribute ,normal white on black screen
        mov cx, 0    ;upper left  corner (row = 0 & col = 0)
        mov dx, 0x184F ;lower right corner (row = 24 & col = 79)
        int 0x10     ;bios interrupt to display

        ;print the menu lines
        mov si, menu1
        call print
        mov si, menu2
        call print
        mov si, menu3
        call print
        mov si, prompt
        call print

wait_int:
        mov ah, 0 ;bios function to wait for keypress
        int 0x16 ; bios interupt to accept keypress
        cmp al, '1'
        je boot_os
        cmp al, '2'
        je advanced_opts
        cmp al, '3'
        je run_bios
        jmp wait_int ; if no valid keypress is given then it runs this loop again

boot_os:
        mov si, bootmsg ;loads the string into source index
        call print   ; calls the print function which prints the string 
        jmp hang

advanced_opts:
        mov si, advmsg ;loads advanced options string into source index
        call print
        jmp hang

run_bios:
        mov si, biosmsg ; loads bios message str into source index
        call print
        jmp hang

;now lets actually implement print function
print:
        lodsb ; loads the data from si to al
        cmp al, 0 ; check if the char is == null terminator
        je done
        mov ah,0x0E ; bios function to print a char 
        int 0x10    ; bios interrupt to print a letter onto screen
        jmp print
done:
    ret

hang:
        jmp $ ; the reason for this infinite loop is because i dont have a functioning kernel yet
              ; and i need cpu to be occupied with these instrcutions so that it wont access other stuff
              ; so thats why need an infinite loop

menu1 db "1. Boot OS", 0x0D, 0x0A, 0
menu2 db "2. Advanced Options", 0x0D, 0x0A, 0
menu3 db "3. Open BIOS Setup", 0x0D, 0x0A, 0
prompt db "select an option (1-3): ", 0

bootmsg db "Loading kernel into memory....", 0x0D, 0x0A, 0
advmsg db "Fetching Advanced Options for kernel.... ", 0x0D, 0x0A, 0
biosmsg db "Opening BIOS Setup", 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0xAA55

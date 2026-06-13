#include <stdint.h>
#include "./include/kernel/console.h"

extern "C" void divide_handler()
{
    // print something to VGA/serial
       for (;;)
        asm volatile("cli; hlt");
}

extern "C" void gpf_handler(uint32_t error_code)
{
    
    for (;;)
        asm volatile("cli; hlt");
}
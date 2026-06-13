#include<stdint.h>
#include "./include/x86_arch/gdt.h"
#include "./include/x86_arch/idt.h"
#include "./include/kernel/limits.h"
#include "./include/kernel/traits.h"
#include "./include/kernel/string.h"
#include "./include/kernel/console.h"

#define loop while(1)
#define no_mangle extern "C"

typedef void (*constructor) ();

no_mangle constructor start_ctors;
no_mangle constructor end_ctors;
no_mangle void call_constructors(){
    for(constructor* i = &start_ctors ; i != &end_ctors; ++i){
        (*i)();
    }
}

no_mangle void kernel_main(
    void* multiboot_struct,
    unsigned int magic_number
)
{
    GlobalDescriptorTable gdt;
    idt_init();

    Console::println("[OK] GDT Loaded Correctly");
    Console::println("[OK] IDT Loaded Correctly");
    Console::printHex(0xdeadbeef);
    int x = 10;
    int y = 10;
    int z = 10;
    Console::printHex((uintptr_t)&x,(uintptr_t)&y,(uintptr_t)&z);


    loop{}
}
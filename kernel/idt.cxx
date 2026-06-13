#include "./include/x86_arch/idt.h"

static IDTEntry idt[256];

static void set_gate(uint8_t vector, void (*handler)())
{
    uint32_t addr = reinterpret_cast<uint32_t>(handler);

    idt[vector].offset_low  = addr & 0xFFFF;
    idt[vector].selector    = 0x10; // kernel code segment
    idt[vector].zero        = 0;
    idt[vector].type_attr   = 0x8E; // interrupt gate
    idt[vector].offset_high = addr >> 16;
}

void idt_init()
{
    IDTPointer idtr;

    set_gate(0, isr0);     // divide by zero
    set_gate(13, isr13);   // general protection fault

    idtr.limit = sizeof(idt) - 1;
    idtr.base  = reinterpret_cast<uint32_t>(&idt);

    asm volatile("lidt %0" : : "m"(idtr));
}
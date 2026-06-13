#include"./include/x86_arch/gdt.h"

//Author : Mazeed A.
//License : GPL v3

extern void flush();

namespace GDT{
    Entry Entries[5];
    Reference gdtReference;

    void initGDT(){
        gdtReference.limit = (sizeof(Entries)) -1 ;
        gdtReference.base = &Entries;
    }


}
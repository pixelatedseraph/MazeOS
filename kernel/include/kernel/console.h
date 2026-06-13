#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "vga.h"
#include"string.h"

namespace Console{ // Handles Printing Text and Accepting I/P from keyboard
    template<typename... Args>
    void print(Args... args){
        (VGA::write(args),...);
        if(VGA::currentCol <= VGA::vgaCols)
            VGA::write(' ');
    }
    template<typename... Args>
    void println(Args... args){
        (print(args),...);
        uint32_t start =   VGA::vgaCols * (VGA::currentRow - 1)  + (VGA::currentCol - 1);
        uint32_t end   =   VGA::vgaCols * (VGA::currentRow - 1)  + (VGA::vgaCols - 1);
        for(start; start <= end ; ++start){
           VGA::writeChar(' '); 
        }
    }
}

#endif
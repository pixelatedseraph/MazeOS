#ifndef __VGA_H
#define __VGA_H


#include<stdint.h>
#include"string.h"

namespace VGA{
    constexpr uint32_t vgaRows = 25;
    constexpr uint32_t vgaCols = 80;

    extern uint32_t index; //linear vga buffer indexing
    extern uint32_t currentRow;
    extern uint32_t currentCol;

    void writeChar(uint8_t ch);
    void writeString(const char* string);
    void write(uint8_t ch);
    void write(const char* fmt);


    template<TraitBounds::Integral T> 
    void write(T integralValue){
        char stringBuffer[64];
        char finalBuffer[64];
        stringBuffer[String::integralToAscii(integralValue,stringBuffer)] = '\0';
        finalBuffer[String::reverse(finalBuffer,stringBuffer)] = '\0';
        writeString(finalBuffer);
    }

    void clearScreen();
}

#endif
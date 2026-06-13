#include "./include/kernel/vga.h"
#include "./include/kernel/string.h"

namespace VGA{ // c-styled api for c++ kernel
    volatile uint16_t* UniversalVgaBuffer  = (volatile uint16_t*)0xB8000;

    uint32_t index = 0; //linear vga buffer indexing
    uint32_t currentRow = 1;
    uint32_t currentCol = 1;

    //different color schemes
    void writeChar(uint8_t ch, uint8_t fg,uint8_t bg,uint32_t index){
        uint16_t attribute = (bg << 4) | (fg & 0x0F);
        volatile uint16_t* UniversalVgaBuffer  = (volatile uint16_t*)0xB8000;
        UniversalVgaBuffer[index] = ch | (attribute << 8);
    }
    //for the classic white-on-black color scheme
    void writeChar(uint8_t ch){
        uint16_t attribute = (0x0 << 4 ) | (0x0F & 0x0F); //  white on black
        if(currentCol > vgaCols) {
            currentCol = 1;
            currentRow +=1;
        }
        UniversalVgaBuffer[index++] = ch | (attribute << 8);
        currentCol++;
    }

    //printing a string by looping writeChar function
    void writeString(const char* string){
        uint32_t stringLength = String::getStringLength(string);
        for(int i = 0 ; i < stringLength ; ++i){
            writeChar(string[i]);
        }
    }

    //generic interface for writing 
    void write(uint8_t ch){
        writeChar(ch);
    }

    void write(const char* fmt){
        writeString(fmt);
    }

    //sets the provided line with empty character
    void clearLine(uint32_t lineNumber){
        uint32_t start =   VGA::vgaCols * (lineNumber - 1)  + (1 - 1);
        uint32_t end   =   VGA::vgaCols * (lineNumber - 1)  + (VGA::vgaCols - 1);
        for(start; start <= end ; ++start){
            UniversalVgaBuffer[start] = ' ';
        }
    }
    
    void clearScreen(){
        for(int i = 1 ; i <= 25; ++i){
            clearLine(i);
        }
        index = 0;
        currentCol = 1;
        currentRow = 1;
    }

    //consumes a c-styled string to modify the vga memory buffer (discarded)
    void primitivePrint(const char* str){ //error when two instances of this function are called
        volatile uint16_t* const VGAMemoryBuffer = reinterpret_cast<volatile uint16_t*>(0xb8000);
        uint8_t ch;
        for(int i = 0 ; str[i] != '\0'; ++i){
            ch = static_cast<uint8_t>(str[i]);
            VGAMemoryBuffer[i] = (VGAMemoryBuffer[i] & 0xFF00) | ch;
        }
    }

}
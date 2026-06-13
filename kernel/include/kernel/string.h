#ifndef __STRING_H
#define __STRING_H


#include<stdint.h>
#include"traits.h"

namespace String{
    uint32_t getStringLength(const char* str);
    uint32_t reverse(char* dst,char* src);
    bool isSpace(char ch);
    bool isDigit(char ch);
    char digitToChar(uint32_t digit);

    template<TraitBounds::Integral T>
    T reverseDigit(T digit){
        T result = 0;
        T tmp = digit;
        while(tmp > 0){
            result = result*10 + tmp % 10;
            tmp = tmp / 10;
        }
        return result;
    }

    template<TraitBounds::Integral T>
    uint32_t integralToAscii(T digit,char* resBuffer){
        if(digit == 0){
            resBuffer[0] = 48;
            return 1;
        }
        T Digit = digit;
        uint32_t index = 0;
        while(Digit > 0){
            T currentDigit = Digit % 10;
            resBuffer[index++] = (char)(48 + currentDigit);
            Digit = Digit / 10;
        }
        return index;
    }
    void toHex(uintptr_t memoryAddress,char* resBuffer);
}

#endif
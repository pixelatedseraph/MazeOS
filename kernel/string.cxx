#include "./include/kernel/string.h"

namespace String{
    uint32_t getStringLength(const char* str){
        uint32_t stringLength = 0;
        while(str[stringLength] != '\0'){
            stringLength++;
        }
        return stringLength;
    }

    uint32_t reverse(char* dst,char* src){
        uint32_t sourceLength =  getStringLength(src);
        for(int i = sourceLength-1 ; i >= 0 ; --i){
            dst[(sourceLength-1) - i] = src[i];
        }
        return sourceLength;
    }

    bool isSpace(char ch){
        return ch == ' ' ? true : false;
    }

    bool isDigit(char ch){
        return ch >= 48 && ch <= 57 ? true : false;
    }

    char digitToChar(uint32_t digit){
        return 48+digit;
    }

    void toHex(uintptr_t memoryAddress,char* resBuffer){
        uintptr_t tmp = memoryAddress;
        uintptr_t rem;
        uint32_t idx = 0;
        while(tmp > 0){
            rem = tmp % 16;
            if(rem >= 0 && rem <= 9){
                resBuffer[idx++] = digitToChar(rem);
                tmp = tmp / 16;
                continue;
            }
            if(rem >= 10 && rem <= 15){
                resBuffer[idx++] = (65 + rem) - 10;
                tmp = tmp /16;
                continue;
            }
        }
        resBuffer[idx] = '\0';
        char tempBuffer[128];
        tempBuffer[reverse(tempBuffer,resBuffer)] = '\0';

        resBuffer[0] = '0';
        resBuffer[1] = 'x';

        for(uint32_t i = 0 ; i < idx ; ++i){
            resBuffer[i+2] = tempBuffer[i];
        }

        resBuffer[idx+2] = '\0';
    }
}


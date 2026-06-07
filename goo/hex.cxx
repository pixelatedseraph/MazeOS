#include<iostream>
#include<cstdint>

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

    char digitToChar(uint32_t digit){
        return 48+digit;
    }

    uint32_t toHex(uintptr_t memoryAddress,char* resBuffer){
        uintptr_t tmp = memoryAddress;
        uintptr_t rem;
        uint32_t idx = 0;
        //resBuffer[idx++] = '0';
        //resBuffer[idx++] = 'x';
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
        resBuffer[idx] = '\0'; // reversed
        char finalbuffer[128];
        finalbuffer[reverse(finalbuffer,resBuffer)] = '\0'; //original
        
        resBuffer[0] = '0';
        resBuffer[1] = 'x';

        for(int i = 0 ; i < idx ; ++i){
             resBuffer[i+2] = finalbuffer[i];
         }

         resBuffer[idx+2] = '\0';

        return idx;
    }

int main(){
    uintptr_t foo = 0x123F;
    char buff[128];
    toHex(foo,buff);
    std::cout<<buff<<std::endl;
    return 0;
}
#include<stdio.h>
#include<stdint.h>
#include<concepts>
#include<type_traits>

uint32_t strlen(const char* str){
        uint32_t stringLength = 0;
        while(str[stringLength] != '\0'){
            stringLength++;
        }
        return stringLength;
    }

void myprint(const char* str){
    printf("%s",str);
}


template<typename... Args>
void printFoo(Args... args){
    (myprint(args),...);
}

    int reverseIntegerDigit(int digit){
        int result = 0;
        int tmp = digit;
        while(tmp > 0){
            result = result*10 + tmp % 10;
            tmp = tmp / 10;
        }
        return result;
    }


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

        uint32_t integerToAscii(int digit,char* resBuffer){
        if(digit == 0){
            resBuffer[0] = 48;
            return 1;
        }
        int Digit = digit;
        uint32_t index = 0;
        while(Digit > 0){
            int currentDigit = Digit % 10;
            resBuffer[index++] = (char)(48 + currentDigit);
            Digit = Digit / 10;
        }
        return index;
    }


        uint32_t __integerToAscii(int digit,char* resBuffer){
        uint32_t index = 0;
        int tmp = digit;
        while(tmp > 0){
            int currentDigit = tmp % 10;
            resBuffer[index++] = (char)(48 + currentDigit);
            tmp = tmp / 10;
        }
        return index;
    }

    // uint32_t reverse(char* dst,char* src){
    //     uint32_t sourceLength =  strlen(src);
    //     for(int i = sourceLength-1 ; i >= 0 ; --i){
    //         dst[(sourceLength-1) - i] = src[i];
    //     }
    //     return sourceLength;
    // }




int main(){
    char* str = "helrlo world";
    char* str1 = "";
    char* str2 = "aaaaa";
    char* str3 = "!@#$%^&*()";

    //printf("%d %d %d %d",strlen(str),strlen(str1),strlen(str2),strlen(str3));
    //printFoo("hello"," welcome "," to "," mazeos ");
    char res[150];
    res[integerToAscii(12340,res)] ='\0';
 //   printf("%s\n",res);

    char* foo = "mazeed";
    char dest[1024];

    dest[reverse(dest,foo)] = '\0';
   //printf("%s\n",dest);
    
        char stringBuffer[16];
        char finalBuffer[16];
        stringBuffer[integerToAscii(0,stringBuffer)] = '\0';
        finalBuffer[reverse(finalBuffer,stringBuffer)] = '\0';

        printf("%s\n",finalBuffer);

    return 0;
}
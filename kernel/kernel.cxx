#include<stdint.h>

#define CHAR_MAX  127
#define CHAR_MIN -128

#define UNSIGNED_CHAR_MAX 255
#define UNSIGNED_CHAR_MIN 0

#define SHORT_MAX  32767
#define SHORT_MIN -32768

#define UNSIGNED_SHORT_MAX 65535
#define UNSIGNED_SHORT_MIN 0

#define INT_MAX  2147483647
#define INT_MIN -2147483648

#define UNSIGNED_INT_MAX 4294967295
#define UNSIGNED_INT_MIN 0

#define LONG_MAX INT_MAX
#define LONG_MIN INT_MIN

#define UNSIGNED_LONG_MAX UNSIGNED_INT_MAX
#define UNSIGNED_LONG_MIN UNSIGNED_INT_MIN

#define LONG_LONG_MAX 9223372036999999999
#define LONG_LONG_MIN -9223372037000000000

#define UNSIGNED_LONG_LONG_MAX 18446744069999999999
#define UNSIGNED_LONG_LONG_MIN 0


namespace TraitBounds{
    template<typename T>
    struct is_integral{
        static constexpr bool value = false;
    };

    template<> struct is_integral<int> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned int> {static constexpr bool value = true; }; 
    template<> struct is_integral<short> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned short> {static constexpr bool value = true; }; 
    template<> struct is_integral<long> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned long> {static constexpr bool value = true; }; 
    template<> struct is_integral<long long> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned long long> {static constexpr bool value = true; }; 

    template<typename T,typename U>
    struct is_same{
        static constexpr bool value = false;
    };

    template<typename T>
    struct is_same<T,T>{
        static constexpr bool value = true;
    };


    template <typename T>
    concept Integral = is_integral<T>::value;

    template<typename T>
    concept SignedIntegral = Integral<T> && (T(-1) < T(0));

    template<typename T>
    concept UnsignedIntegral = Integral<T> && !(T(-1) < T(0));
 
    template<typename T,typename U>
    inline constexpr bool is_same_v = is_same<T,U>::value;
}


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


namespace VGA{ // c-styled api for c++ kernel

    //different color schemes
    void writeChar(uint8_t ch, uint8_t fg,uint8_t bg,uint32_t index){
        uint16_t attribute = (bg << 4) | (fg & 0x0F);
        volatile uint16_t* UniversalVgaBuffer  = (volatile uint16_t*)0xB8000;
        UniversalVgaBuffer[index] = ch | (attribute << 8);
    }
    //for the classic white-on-black color scheme
    void writeChar(uint8_t ch){
        static uint32_t index = 0;
        uint16_t attribute = (0x0 << 4 ) | (0x0F & 0x0F); //  white on black
        volatile uint16_t* UniversalVgaBuffer  = (volatile uint16_t*)0xB8000;
        UniversalVgaBuffer[index++] = ch | (attribute << 8);
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

    template<TraitBounds::Integral T> 
    void write(T integralValue){
        char stringBuffer[64];
        char finalBuffer[64];
        stringBuffer[String::integralToAscii(integralValue,stringBuffer)] = '\0';
        finalBuffer[String::reverse(finalBuffer,stringBuffer)] = '\0';
        writeString(finalBuffer);
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

namespace Console{ // Handles Printing Text and Accepting I/P from keyboard
    template<typename... Args>
    void print(Args... args){
        (VGA::write(args),...);
    }
}

extern "C" void kernel_main(void* multiboot_struct,unsigned int magic_number){ //accept multiboot structure     
    char result[32];
    String::toHex(reinterpret_cast<uintptr_t>(&kernel_main),result);
    Console::print("kernel_main : ",result);

    while(1);
}
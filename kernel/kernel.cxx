#include<stdint.h>
#include<limits.h>


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

    template <typename T>
    concept Integral = is_integral<T>::value;

    template<typename T>
    concept SignedIntegral = Integral<T> && (T(-1) < T(0));

    template<typename T>
    concept UnsignedIntegral = Integral<T> && !(T(-1) < T(0));
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


    template<TraitBounds::Integeral T>
    T reverseDigit(T digit){
        T result = 0;
        T tmp = digit;
        while(tmp > 0){
            result = result*10 + tmp % 10;
            tmp = tmp / 10;
        }
        return result;
    }
    
    template<TraitBounds::Integeral T>
    uint32_t integralToAscii(T digit,char* resBuffer){
        if(digit == 0){
            resBuffer[0] = 48;
            return 1;
        }
        T Digit = digit;
        uint32_t index = 0;
        while(Digit > 0){
            int currentDigit = Digit % 10;
            resBuffer[index++] = (char)(48 + currentDigit);
            Digit = Digit / 10;
        }
        return index;
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

    template<TraitBounds::Integeral T> 
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
    unsigned long goo = (unsigned long)12345678912;
    if(goo <= ULONG_MAX){
        Console::print("FIRST GOO : ",goo," SECOND GOO: " ); 
        char buff[128];
        buff[String::integralToAscii(goo,buff)] = '\0';
        Console::print(buff);
        while(1);
    }
    //Console::print("Hello"," Welcome"," To"," MazeOS ");
    Console::print('a');
    Console::print('b');
    Console::print(goo);
    //print("hello"," welcome");
    while(1);
}
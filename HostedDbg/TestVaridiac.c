#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdarg.h>

#define FE_1(f,x) f(x)
#define FE_2(f,x,...) f(x); FE_1(f,__VA_ARGS__)
#define FE_3(f,x,...) f(x); FE_2(f,__VA_ARGS__)
#define FE_4(f,x,...) f(x); FE_3(f,__VA_ARGS__)
#define FE_5(f,x,...) f(x); FE_4(f,__VA_ARGS__)
#define FE_6(f,x,...) f(x); FE_5(f,__VA_ARGS__)
#define FE_7(f,x,...) f(x); FE_6(f,__VA_ARGS__)
#define FE_8(f,x,...) f(x); FE_7(f,__VA_ARGS__)
#define FE_9(f,x,...) f(x); FE_8(f,__VA_ARGS__)
#define FE_10(f,x,...) f(x); FE_9(f,__VA_ARGS__)
#define FE_11(f,x,...) f(x); FE_10(f,__VA_ARGS__)
#define FE_12(f,x,...) f(x); FE_11(f,__VA_ARGS__)
#define FE_13(f,x,...) f(x); FE_12(f,__VA_ARGS__)
#define FE_14(f,x,...) f(x); FE_13(f,__VA_ARGS__)
#define FE_15(f,x,...) f(x); FE_14(f,__VA_ARGS__)
#define FE_16(f,x,...) f(x); FE_15(f,__VA_ARGS__)
#define FE_17(f,x,...) f(x); FE_16(f,__VA_ARGS__)
#define FE_18(f,x,...) f(x); FE_17(f,__VA_ARGS__)
#define FE_19(f,x,...) f(x); FE_18(f,__VA_ARGS__)
#define FE_20(f,x,...) f(x); FE_19(f,__VA_ARGS__)
#define FE_21(f,x,...) f(x); FE_20(f,__VA_ARGS__)
#define FE_22(f,x,...) f(x); FE_21(f,__VA_ARGS__)
#define FE_23(f,x,...) f(x); FE_22(f,__VA_ARGS__)
#define FE_24(f,x,...) f(x); FE_23(f,__VA_ARGS__)
#define FE_25(f,x,...) f(x); FE_24(f,__VA_ARGS__)
#define FE_26(f,x,...) f(x); FE_25(f,__VA_ARGS__)
#define FE_27(f,x,...) f(x); FE_26(f,__VA_ARGS__)
#define FE_28(f,x,...) f(x); FE_27(f,__VA_ARGS__)
#define FE_29(f,x,...) f(x); FE_28(f,__VA_ARGS__)
#define FE_30(f,x,...) f(x); FE_29(f,__VA_ARGS__)
#define FE_31(f,x,...) f(x); FE_30(f,__VA_ARGS__)
#define FE_32(f,x,...) f(x); FE_31(f,__VA_ARGS__)
#define FE_33(f,x,...) f(x); FE_32(f,__VA_ARGS__)
#define FE_34(f,x,...) f(x); FE_33(f,__VA_ARGS__)
#define FE_35(f,x,...) f(x); FE_34(f,__VA_ARGS__)
#define FE_36(f,x,...) f(x); FE_35(f,__VA_ARGS__)
#define FE_37(f,x,...) f(x); FE_36(f,__VA_ARGS__)
#define FE_38(f,x,...) f(x); FE_37(f,__VA_ARGS__)
#define FE_39(f,x,...) f(x); FE_38(f,__VA_ARGS__)
#define FE_40(f,x,...) f(x); FE_39(f,__VA_ARGS__)
#define FE_41(f,x,...) f(x); FE_40(f,__VA_ARGS__)
#define FE_42(f,x,...) f(x); FE_41(f,__VA_ARGS__)
#define FE_43(f,x,...) f(x); FE_42(f,__VA_ARGS__)
#define FE_44(f,x,...) f(x); FE_43(f,__VA_ARGS__)
#define FE_45(f,x,...) f(x); FE_44(f,__VA_ARGS__)
#define FE_46(f,x,...) f(x); FE_45(f,__VA_ARGS__)
#define FE_47(f,x,...) f(x); FE_46(f,__VA_ARGS__)
#define FE_48(f,x,...) f(x); FE_47(f,__VA_ARGS__)
#define FE_49(f,x,...) f(x); FE_48(f,__VA_ARGS__)
#define FE_50(f,x,...) f(x); FE_49(f,__VA_ARGS__)
#define FE_51(f,x,...) f(x); FE_50(f,__VA_ARGS__)
#define FE_52(f,x,...) f(x); FE_51(f,__VA_ARGS__)
#define FE_53(f,x,...) f(x); FE_52(f,__VA_ARGS__)
#define FE_54(f,x,...) f(x); FE_53(f,__VA_ARGS__)
#define FE_55(f,x,...) f(x); FE_54(f,__VA_ARGS__)
#define FE_56(f,x,...) f(x); FE_55(f,__VA_ARGS__)
#define FE_57(f,x,...) f(x); FE_56(f,__VA_ARGS__)
#define FE_58(f,x,...) f(x); FE_57(f,__VA_ARGS__)
#define FE_59(f,x,...) f(x); FE_58(f,__VA_ARGS__)
#define FE_60(f,x,...) f(x); FE_59(f,__VA_ARGS__)
#define FE_61(f,x,...) f(x); FE_60(f,__VA_ARGS__)
#define FE_62(f,x,...) f(x); FE_61(f,__VA_ARGS__)
#define FE_63(f,x,...) f(x); FE_62(f,__VA_ARGS__)
#define FE_64(f,x,...) f(x); FE_63(f,__VA_ARGS__)

#define GET_MACRO(                          \
    _1,_2,_3,_4,_5,_6,_7,_8,                \
    _9,_10,_11,_12,_13,_14,_15,_16,         \
    _17,_18,_19,_20,_21,_22,_23,_24,        \
    _25,_26,_27,_28,_29,_30,_31,_32,        \
    _33,_34,_35,_36,_37,_38,_39,_40,        \
    _41,_42,_43,_44,_45,_46,_47,_48,        \
    _49,_50,_51,_52,_53,_54,_55,_56,        \
    _57,_58,_59,_60,_61,_62,_63,_64,        \
    NAME,...) NAME

#define FOR_EACH(f,...)                                 \
    GET_MACRO(__VA_ARGS__,                              \
    FE_64,FE_63,FE_62,FE_61,FE_60,FE_59,FE_58,FE_57,    \
    FE_56,FE_55,FE_54,FE_53,FE_52,FE_51,FE_50,FE_49,    \
    FE_48,FE_47,FE_46,FE_45,FE_44,FE_43,FE_42,FE_41,    \
    FE_40,FE_39,FE_38,FE_37,FE_36,FE_35,FE_34,FE_33,    \
    FE_32,FE_31,FE_30,FE_29,FE_28,FE_27,FE_26,FE_25,    \
    FE_24,FE_23,FE_22,FE_21,FE_20,FE_19,FE_18,FE_17,    \
    FE_16,FE_15,FE_14,FE_13,FE_12,FE_11,FE_10,FE_9,     \
    FE_8,FE_7,FE_6,FE_5,FE_4,FE_3,FE_2,FE_1             \
)(f,__VA_ARGS__)

[[maybe_unused]]
static inline const char* _2byte_uinteger_to_string(uint16_t number){
    static char buffer[8];

    if(number == 0){
            buffer[0] = 48;
            buffer[1] = '\0';
            return buffer;
        }
        uint16_t tmp = number;
        uint16_t index = 0;
        while(tmp > 0){
            uint16_t currentDigit = tmp % 10;
            buffer[index++] = (char)(48 + currentDigit);
            tmp = tmp / 10;
        }
        buffer[index] = '\0';
        return buffer; 
} 

//caller aka print() must call free for this, the buffer recieved by reverse() is to be called
#define unsigned_integer_to_string(number) ({                                                                                                           \
    typeof(number) _number = number;                                                                                                                    \
    static_assert(__builtin_types_compatible_p(typeof(_number),uint16_t) ||                                                                             \
                  __builtin_types_compatible_p(typeof(_number),uint32_t) ||                                                                             \
                  __builtin_types_compatible_p(typeof(_number),uint64_t),"[Error] Substitution failure is an error(sfiae)");                            \
                                                                                                                                                        \
    char _buffer[32];                                                                                                                                   \
    typeof(_number) _tmp = _number;                                                                                                                     \
    typeof(_number) _index = 0;                                                                                                                         \
    typeof(_number) _current_digit;                                                                                                                     \
                                                                                                                                                        \
    if(_number == 0){                                                                                                                                   \
        _buffer[0] = 48;                                                                                                                                \
        _buffer[1] = '\0';                                                                                                                              \
    }                                                                                                                                                   \
    else{                                                                                                                                               \
        while(_tmp > 0){                                                                                                                                \
                _current_digit = _tmp % 10;                                                                                                             \
                _buffer[_index++] = (char)(48 + _current_digit);                                                                                        \
                _tmp = _tmp / 10;                                                                                                                       \
            }                                                                                                                                           \
            _buffer[_index] = '\0';                                                                                                                     \
        }                                                                                                                                               \
        char* _res = reverse(_buffer);                                                                                                                  \
        _res;                                                                                                                                           \
})                                  


//the buffer "_final_buffer" is to freed by the caller aka print()
#define integer_to_string(number)({                                                                                                                      \
    typeof(number) _number = number;                                                                                                                     \
    static_assert(__builtin_types_compatible_p(typeof(_number),int16_t)  ||                                                                              \
                  __builtin_types_compatible_p(typeof(_number),int32_t)  ||                                                                              \
                  __builtin_types_compatible_p(typeof(_number),int64_t),"[Error] Substitution failure is an error(sfiae)");                              \
    bool _is_negative = false;                                                                                                                           \
    char _buffer[32];                                                                                                                                    \
    char* _final_buffer = malloc(32);                                                                                                                    \
    typeof(_number) _tmp = _number;                                                                                                                      \
    typeof(_number) _index = 0;                                                                                                                          \
    typeof(_number) _current_digit;                                                                                                                      \
                                                                                                                                                         \
    if(_number == 0){                                                                                                                                    \
        _buffer[0] = 48;                                                                                                                                 \
        _buffer[1] = '\0';                                                                                                                               \
    }                                                                                                                                                    \
    else{                                                                                                                                                \
        if(_number < 0){                                                                                                                                 \
            _is_negative = true;                                                                                                                         \
            _tmp = -(_number);                                                                                                                           \
        }                                                                                                                                                \
                                                                                                                                                         \
        while(_tmp > 0){                                                                                                                                 \
            _current_digit = _tmp % 10;                                                                                                                  \
            _buffer[_index++] = (char)(48 + _current_digit);                                                                                             \
            _tmp = _tmp / 10;                                                                                                                            \
        }                                                                                                                                                \
         _buffer[_index] = '\0';                                                                                                                         \
    }                                                                                                                                                    \
                                                                                                                                                         \
    /* dont forget to free at the end of return */                                                                                                       \
    char* _reversed_buff = reverse(_buffer);                                                                                                             \
                                                                                                                                                         \
    if(_is_negative == true){                                                                                                                            \
        _final_buffer[0] = '-';                                                                                                                          \
        memcpy(_final_buffer+1,_reversed_buff,strlen(_reversed_buff)+1);                                                                                 \
    }                                                                                                                                                    \
    else{                                                                                                                                                \
        memcpy(_final_buffer,_reversed_buff,strlen(_reversed_buff)+1);                                                                                   \
    }                                                                                                                                                    \
    free(_reversed_buff);                                                                                                                                \
    _final_buffer;                                                                                                                                       \
})                                                                             


//char to str
//int  to str
//uint to str
//int  to hex

#define uinteger_to_string(number)                    \
({                                                    \
    const char* _result_str = _Generic((number),      \
        uint16_t : _2byte_uinteger_to_string,         \
        const uint16_t : _2byte_uinteger_to_string,   \
        uint32_t : _4byte_uinteger_to_string,         \
        const uint32_t : _4byte_uinteger_to_string,   \
        uint64_t : _8byte_uinteger_to_string,         \
        const uint64_t : _8byte_uinteger_to_string,   \
        default : print_unknown                       \
    )(number)                                         \
    _result_str;                                      \
})


char* reverse(char* src){
    uint32_t sourceLength =  strlen(src);
    char* dst = malloc(sourceLength+1);
    for(int i = sourceLength-1 ; i >= 0 ; --i){
        dst[(sourceLength-1) - i] = src[i];
        }
    dst[sourceLength] = '\0';
    return dst;
}

[[maybe_unused]]
void auto_free(void* ptr){
    if(!ptr){
        free(*(void**)ptr);
    }
}


void print_int(int x){
    printf("%d ",x);
}

#define print_str(string) ({    \
    printf("%s ",string);       \
})                              \

void print_double(double x){
    printf("%.3f ",x);
}

/* define print_one(x)   \
    _Generic((x),       \
    int :  print_int,   \
    char* : print_str,   \
    const char* : print_str,   \
    double : print_double  \
    )(x)
*/

#define _integer_types(_number) __builtin_types_compatible_p(typeof(_number),int16_t) ||      \
                  __builtin_types_compatible_p(typeof(_number),int32_t)     ||      \
                  __builtin_types_compatible_p(typeof(_number),int64_t)

#define _unsigned_types(_number) __builtin_types_compatible_p(typeof(_number),uint16_t)  ||    \
                  __builtin_types_compatible_p(typeof(_number),uint32_t)       ||    \
                  __builtin_types_compatible_p(typeof(_number),uint64_t)                  


#define integer_types(number)                               \
    int16_t :   printf("%s ",integer_to_string(number)),    \
    int32_t :   printf("%s ",integer_to_string(number)),    \
    int64_t :   printf("%s "integer_to_string(number)),     \

#define unsigned_integer_types(number)              \
    uint16_t : printf("%s ",unsigned_integer_to_string(number)),  \
    uint32_t : printf("%s ",unsigned_integer_to_string(number)),  \
    uint64_t : printf("%s ",unsigned_integer_to_string(number)),  \

#define string_types(string)            \
    char* : print("%s ",string),        \
    const char* : print("%s ",string),  \

#define print_one(x)   ({                                       \
    _Generic((x),                                               \
        integer_types(x)                                        \
        unsigned_integer_types(x),                              \
        string_types(x)                                         \
    )                                                           \
})


#define print(...) FOR_EACH(print_one,__VA_ARGS__)    

int main(){
    //char buff[128];
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
    #pragma GCC diagnostic ignored "-Wgnu-statement-expression-from-macro-expansion"

    print(12345);

    #pragma GCC diagnostic pop

    
    return 0;
}
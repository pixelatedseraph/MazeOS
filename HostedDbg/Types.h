#ifndef TYPES_H
#define TYPES_H

#include<stdint.h>
#include<stdbool.h>
#include<uchar.h>


typedef uint8_t BOOLEAN;

typedef uint8_t UINT8;
typedef int8_t INT8;

typedef uint16_t UINT16;
typedef int16_t INT16;

typedef uint32_t UINT32;
typedef int32_t INT32;

typedef uint64_t UINT64;
typedef int64_t INT64;

typedef uint64_t UINTN;
typedef int64_t INTN;

typedef char CHAR8; 
//for UTF-16 support ,every char is 2bytes
//      code points <= 0xFFFF_FFFF
#ifndef _UCHAR_H
    typedef uint_least16_t char16_t;
#endif

typedef char16_t CHAR16;

typedef void VOID;

#define CONST const

#endif
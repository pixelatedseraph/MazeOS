 #ifndef __EFI_H
#define __EFI_H

#include<stdint.h>
#if __has_include(<uchar.h>)
    #include<uchar.h>
#endif

/* purely visual,no actual purpose */
// Spec 2.10 sec 2.4
#define IN
#define OUT
#define OPTIONAL
#define CONST const

// Defines calling conventions for EFI defined functions

// Spec 2.10 sec 2.3
#define EFIAPI __attribute__((ms_abi)) //x86_64 mircosoft calling convention

//Data types : Spec 2.10 sec 2.3

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

typedef struct [[gnu::packed]]{
    UINT32 TimeLow;
    UINT16 TimeMid;
    UINT16 TimeHighAndVersion;
    UINT8 ClockSeqHighAndReserved;
    UINT8 ClockSeqLow;
    UINT8 Node[6];
} EFI_GUID;

typedef UINTN EFI_STATUS;
typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

/* Function typedefs */
//Data types : Spec 2.10 sec 4.1.1

//Todo : Remove this system table definition when its defined later
typedef void EFI_SYSTEM_TABLE;

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT) (
    IN  EFI_HANDLE               ImageHandle,
    IN  EFI_SYSTEM_TABLE*        SystemTable
);




#endif
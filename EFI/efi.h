//READ EVERY TODO CAREFULLY AND FIX THEM ASAP!

#ifndef __EFI_H
#define __EFI_H

#include<stdint.h>
#include<stdbool.h>
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

//EFI_STATUS codes - spec 2.11 Appendix D
#define EFI_SUCCESS 0ULL


//EFI_TABLE_HEADER spec 2.10 sec 4.2.1
typedef struct{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
}EFI_TABLE_HEADER;

//EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL spec 2.11 sec 12.4.1
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

//EFI_TEXT_RESET: UEFI spec 2.11 sec 12.4.1 (Protocol {function pointer} )
//Resets the text output device hardware
typedef
EFI_STATUS (EFIAPI *EFI_TEXT_RESET)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    IN BOOLEAN                          ExtendedVerification      
);

//EFI_TEXT_STRING: spec 2.11 sec 12.4.3 (Protocol {function pointer} )
//Writes a string to the output device
typedef 
EFI_STATUS (EFIAPI *EFI_TEXT_STRING)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  This,
    IN CHAR16*                            String
);

//EFI_TEXT_CLEAR_SCREEN: spec 2.11 sec 12.4.3 (Protocol {function pointer} )
//Clears the output device display to the currently selected bg color
typedef 
EFI_STATUS (EFIAPI *EFI_TEXT_CLEAR_SCREEN)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*    This
);

//TODO : implement the following protocols and remove VOID 
#define EFI_TEXT_TEST_STRING VOID*
#define EFI_TEXT_QUERY_MODE  VOID*
#define EFI_TEXT_SET_MODE  VOID*
#define EFI_TEXT_SET_ATTRIBUTE VOID*
#define EFI_TEXT_SET_CURSOR_POSITION VOID*
#define EFI_TEXT_ENABLE_CURSOR  VOID*
#define SIMPLE_TEXT_OUTPUT_MODE VOID

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL{
    EFI_TEXT_RESET                  Reset;
    EFI_TEXT_STRING                 OutputString;
    EFI_TEXT_TEST_STRING            TestString;
    EFI_TEXT_QUERY_MODE             QueryMode;
    EFI_TEXT_SET_MODE               SetMode;
    EFI_TEXT_SET_ATTRIBUTE          SetAttribute;
    EFI_TEXT_CLEAR_SCREEN           ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION    SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR          EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE*        Mode;
}EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;


//TODO : implement the following protocols and remove VOID 
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL  VOID
#define EFI_RUNTIME_SERVICES VOID
#define EFI_BOOT_SERVICES VOID
#define EFI_CONFIGURATION_TABLE VOID

//EFI_SYSTEM_TABLE spec 2.11 sec 4.3.1
typedef struct {
    EFI_TABLE_HEADER                    Hdr;
    CHAR16*                             FirmwareVendor;
    UINT32                              FirmwareRevision;
    EFI_HANDLE                          ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL*     ConIn;
    EFI_HANDLE                          ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*    ConOut;
    EFI_HANDLE                          StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*    StdErr;
    EFI_RUNTIME_SERVICES*               RuntimeServices;
    EFI_BOOT_SERVICES*                  BootServices;
    UINTN                               NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE*            ConfigurationTable;
}EFI_SYSTEM_TABLE;



/* Function typedefs */
//Data types : Spec 2.10 sec 4.1.1

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT) (
    IN  EFI_HANDLE               ImageHandle,
    IN  EFI_SYSTEM_TABLE*        SystemTable
);


#endif
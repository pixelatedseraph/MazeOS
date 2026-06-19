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
#define EFI_SUCCESS                         0
#define EFI_LOAD_ERROR                      1 //image failed to load
#define EFI_INVALID_PARAMETER               2
#define EFI_UNSUPPORTED                     3
#define EFI_BAD_BUFFER_SIZE                 4
#define EFI_BUFFER_TOO_SMALL                5
#define EFI_OUT_OF_RESOURCES                9
#define EFI_NOT_FOUND                       14





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


//Atrributes for the below function
//foreground colors
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY 0x08
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F

//background colors
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

//helper macro 
#define EFI_TEXT_ATTR(Foreground,Background) \
    ((Foreground) | ((Background) << 4))

//EFI_TEXT_SET_ATTRIBUTE: spec 2.11 sec 12.4.7 (Protocol {function pointer} )
//Sets the foreground and background color
typedef
EFI_STATUS (EFIAPI *EFI_TEXT_SET_ATTRIBUTE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  This,
    IN UINTN                             Attribute
);

//TODO(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL): implement the following protocols and remove VOID 
#define EFI_TEXT_TEST_STRING VOID*
#define EFI_TEXT_QUERY_MODE  VOID*
#define EFI_TEXT_SET_MODE  VOID*
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


//EFI_BOOT_SERVICES(TABLE): spec 2.11 sec 4.4.1
//Table of pointers to all of boot services
#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

//TODO(EFI_TABLE_HEADER): implement the following and remove VOID
#define EFI_RAISE_TPL                               VOID*
#define EFI_RESTORE_TPL                             VOID*
#define EFI_CREATE_EVENT                            VOID*
#define EFI_SET_TIMER                               VOID*
#define EFI_WAIT_FOR_EVENT                          VOID*  
#define EFI_SIGNAL_EVENT                            VOID*    
#define EFI_CLOSE_EVENT                             VOID*   
#define EFI_CHECK_EVENT                             VOID*       
#define EFI_INSTALL_PROTOCOL_INTERFACE              VOID*                  
#define EFI_REINSTALL_PROTOCOL_INTERFACE            VOID*         
#define EFI_UNINSTALL_PROTOCOL_INTERFACE            VOID*   
#define EFI_HANDLE_PROTOCOL                         VOID*
#define EFI_REGISTER_PROTOCOL_NOTIFY                VOID*
#define EFI_LOCATE_HANDLE                           VOID* 
#define EFI_LOCATE_DEVICE_PATH                      VOID*
#define EFI_INSTALL_CONFIGURATION_TABLE             VOID*
#define EFI_IMAGE_UNLOAD                            VOID*
#define EFI_IMAGE_START                             VOID*
#define EFI_EXIT                                    VOID*
#define EFI_IMAGE_UNLOAD                            VOID*
#define EFI_EXIT_BOOT_SERVICES                      VOID*
#define EFI_GET_NEXT_MONOTONIC_COUNT                VOID*
#define EFI_STALL                                   VOID*
#define EFI_SET_WATCHDOG_TIMER                      VOID*
#define EFI_CONNECT_CONTROLLER                      VOID*
#define EFI_DISCONNECT_CONTROLLER                   VOID*
#define EFI_OPEN_PROTOCOL                           VOID*
#define EFI_OPEN_PROTOCOL_INFORMATION               VOID*
#define EFI_CLOSE_PROTOCOL                          VOID*
#define EFI_OPEN_PROTOCOL_INFORMATION               VOID*
#define EFI_PROTOCOLS_PER_HANDLE                    VOID*
#define EFI_LOCATE_HANDLE_BUFFER                    VOID*
#define EFI_LOCATE_PROTOCOL                         VOID*
#define EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES  VOID*
#define EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES  VOID*
#define EFI_CALCULATE_CRC32                         VOID*
#define EFI_COPY_MEM                                VOID*
#define EFI_SET_MEM                                 VOID*
#define EFI_CREATE_EVENT_EX                         VOID*


//Memory Allocation Services : 2.11 sec 7.2.1
//Definitions for Memory Allocation Serivices

//EFI_ALLOCATE_TYPE
typedef enum{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType,
}EFI_ALLOCATE_TYPE;

//EFI_MEMORY_TYPE
typedef enum{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
}EFI_MEMORY_TYPE;

//EFI_PHYSICAL_ADDRESS
typedef UINT64 EFI_PHYSICAL_ADDRESS;

//EFI_VIRTUAL_ADDRESS
typedef UINT64 EFI_VIRTUAL_ADDRESS;

//Memory Descriptor Version Number
#define EFI_MEMORY_DESCRIPTOR_VERSION 1

//EFI_ALLOCATE_PAGES: spec 2.11 sec 7.2.1 (Protocol {function pointer} )
//Allocates memory pages from the system
typedef
EFI_STATUS (EFIAPI *EFI_ALLOCATE_PAGES)(
    IN      EFI_ALLOCATE_TYPE                    Type,
    IN      EFI_MEMORY_TYPE                      MemoryType,
    IN      UINTN                                Pages,
    IN OUT  EFI_PHYSICAL_ADDRESS*                Memory 
);

//EFI_FREE_PAGES: spec 2.11 sec 7.2.2 (Protocol {function pointer})
//Frees Memory Pages
typedef
EFI_STATUS (EFIAPI *EFI_FREE_PAGES)(
    IN EFI_PHYSICAL_ADDRESS                       Memory,
    IN UINTN                                      Pages                                          
);

//EFI_MEMORY_DESCRIPTOR
typedef struct {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
}EFI_MEMORY_DESCRIPTOR;


//EFI_GET_MEMORY_MAP:  spec 2.11 sec 7.2.3 (Protocol {function pointer})
//returns the current memory map
typedef
EFI_STATUS (EFIAPI* EFI_GET_MEMORY_MAP) (
    IN  OUT UINTN*                              MemoryMapSize,
        OUT EFI_MEMORY_DESCRIPTOR*              MemoryMap,
        OUT UINTN*                              MapKey,
        OUT UINTN*                              DescriptorSize,
        OUT UINT32*                             DescriptorVersion
);

//EFI_ALLOCATE_POOL:  spec 2.11 sec 7.2.4 (Protocol {function pointer})
//allocates pool memory
//status codes  EFI_SUCCESS           The requested number of bytes was allocated.
//              EFI_OUT_OF_RESOURCES  The pool requested could not be allocated.
//              EFI_INVALID_PARAMETER PoolType is in the range EfiMaxMemoryType..0x6FFFFFFF.
//              EFI_INVALID_PARAMETER PoolType is EfiPersistentMemory.
//              EFI_INVALID_PARAMETER Buffer is NULL.
typedef
EFI_STATUS (EFIAPI *EFI_ALLOCATE_POOL)(
    IN      EFI_MEMORY_TYPE                     PoolType,
    IN      UINTN                               Size,
        OUT VOID**                              Buffer
);

//EFI_FREE_POOL : spec 2.11 sec.7.2.5 (Protocol {function pointer })
//Returns pool memory to the system
typedef
EFI_STATUS (EFIAPI *EFI_FREE_POOL)(
    IN VOID*            Buffer
);

typedef struct {
    EFI_TABLE_HEADER                                Hdr;
    //
    // Task Priority Services
    //
    EFI_RAISE_TPL                                   RaiseTPL; // EFI 1.0+
    EFI_RESTORE_TPL                                 RestoreTPL; // EFI 1.0+
    //
    // Memory Services
    //
    EFI_ALLOCATE_PAGES                              AllocatePages; // EFI 1.0+
    EFI_FREE_PAGES                                  FreePages; // EFI 1.0+
    EFI_GET_MEMORY_MAP                              GetMemoryMap; // EFI 1.0+
    EFI_ALLOCATE_POOL                               AllocatePool; // EFI 1.0+
    EFI_FREE_POOL                                   FreePool; // EFI 1.0+
    //
    // Event & Timer Services
    //
    EFI_CREATE_EVENT                                CreateEvent; // EFI 1.0+
    EFI_SET_TIMER                                   SetTimer; // EFI 1.0+
    EFI_WAIT_FOR_EVENT                              WaitForEvent; // EFI 1.0+
    EFI_SIGNAL_EVENT                                SignalEvent; // EFI 1.0+
    EFI_CLOSE_EVENT                                 CloseEvent; // EFI 1.0+
    EFI_CHECK_EVENT                                 CheckEvent; // EFI 1.0+
    //
    // Protocol Handler Services
    //
    EFI_INSTALL_PROTOCOL_INTERFACE                  InstallProtocolInterface; // EFI 1.0+
    EFI_REINSTALL_PROTOCOL_INTERFACE                ReinstallProtocolInterface; // EFI 1.0+
    EFI_UNINSTALL_PROTOCOL_INTERFACE                UninstallProtocolInterface; // EFI 1.0+
    EFI_HANDLE_PROTOCOL                             HandleProtocol; // EFI 1.0+
    VOID*                                           Reserved; // EFI 1.0+
    EFI_REGISTER_PROTOCOL_NOTIFY                    RegisterProtocolNotify; // EFI 1.0+
    EFI_LOCATE_HANDLE                               LocateHandle; // EFI 1.0+
    EFI_LOCATE_DEVICE_PATH                          LocateDevicePath; // EFI 1.0+
    EFI_INSTALL_CONFIGURATION_TABLE                 InstallConfigurationTable; // EFI 1.0+
    //
    // Image Services
    //
    EFI_IMAGE_UNLOAD                                LoadImage; // EFI 1.0+
    EFI_IMAGE_START                                 StartImage; // EFI 1.0+
    EFI_EXIT                                        Exit; // EFI 1.0+
    EFI_IMAGE_UNLOAD                                UnloadImage; // EFI 1.0+
    EFI_EXIT_BOOT_SERVICES                          ExitBootServices; // EFI 1.0+
    //
    // Miscellaneous Services
    //
    EFI_GET_NEXT_MONOTONIC_COUNT                    GetNextMonotonicCount; // EFI 1.0+
    EFI_STALL                                       Stall; // EFI 1.0+
    EFI_SET_WATCHDOG_TIMER                          SetWatchdogTimer; // EFI 1.0+
    //
    // DriverSupport Services
    //
    EFI_CONNECT_CONTROLLER                          ConnectController; // EFI 1.1
    EFI_DISCONNECT_CONTROLLER                       DisconnectController; // EFI 1.1+
    //
    // Open and Close Protocol Services
    //
    EFI_OPEN_PROTOCOL                               OpenProtocol; // EFI 1.1+
    EFI_CLOSE_PROTOCOL                              CloseProtocol; // EFI 1.1+
    EFI_OPEN_PROTOCOL_INFORMATION                   OpenProtocolInformation;// EFI 1.1+
    //
    // Library Services
    //
    EFI_PROTOCOLS_PER_HANDLE                        ProtocolsPerHandle; // EFI 1.1+
    EFI_LOCATE_HANDLE_BUFFER                        LocateHandleBuffer; // EFI 1.1+
    EFI_LOCATE_PROTOCOL                             LocateProtocol; // EFI 1.1+
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES      InstallMultipleProtocolInterfaces; //→EFI 1.1+
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES      UninstallMultipleProtocolInterfaces; //→EFI 1.1+*
    //
    // 32-bit CRC Services
    //
    EFI_CALCULATE_CRC32                             CalculateCrc32; // EFI 1.1+
    //
    // Miscellaneous Services
    //
    EFI_COPY_MEM                                    CopyMem; // EFI 1.1+
    EFI_SET_MEM                                     SetMem; // EFI 1.1+
    EFI_CREATE_EVENT_EX                             CreateEventEx; // UEFI 2.0+
}EFI_BOOT_SERVICES;




//TODO(EFI_SYSTEM_TABLE) : implement the following protocols and remove VOID 
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL  VOID
#define EFI_RUNTIME_SERVICES VOID
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



//EFI_LOADED_IMAGE_PROTOCOL spec 2.10 sec 9.1.1
//Can be used on any image handle to obtain information about the loaded image.
#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1,0x9562,0x11d2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

//Revision Number
#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000     
//TODO(EFI_LOADED_IMAGE_PROTOCOL) Implement the following tables and remove VOID
#define EFI_DEVICE_PATH_PROTOCOL    VOID

//EFI_LOADED_IMAGE_PROTOCOL
typedef struct {
   UINT32                        Revision;
   EFI_HANDLE                    ParentHandle;
   EFI_SYSTEM_TABLE*             SystemTable;

   // Source location of the image
   EFI_HANDLE                    DeviceHandle;
   EFI_DEVICE_PATH_PROTOCOL*     FilePath;
   VOID                          *Reserved;

   // Image’s load options
   UINT32                        LoadOptionsSize;
   VOID                          *LoadOptions;

   // Location where image was loaded
   VOID                          *ImageBase;
   UINT64                        ImageSize;
   EFI_MEMORY_TYPE               ImageCodeType;
   EFI_MEMORY_TYPE               ImageDataType;
   EFI_IMAGE_UNLOAD              Unload;
}EFI_LOADED_IMAGE_PROTOCOL;



#endif

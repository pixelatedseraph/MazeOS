#ifndef __EFI_STRING_H
#define __EFI_STRING_H

#include "efi.h"

#define     ESTR_SENTINEL_STRING L"C0DEF0RF00D!@[s;mmskd*&^%$0-78"

#define max(a,b) ({                     \
    INT64 _maximum =  (a >= b) ? a: b;  \
    _maximum;                           \
})                                      \


#define min(a,b) ({                     \
    INT64 _minimum =  (a >= b) ? b: a;  \
    _minimum;                           \
})                                      \


BOOLEAN     ESTR_CharacterEquals(CHAR16 c1,CHAR16 c2);
UINT64      ESTR_StringLength(CHAR16* String);
INT32       ESTR_StringEquals(CHAR16* String1,CHAR16* String2);
CHAR16      ESTR_PeekAhead(CHAR16* String);


VOID*       ESTR_MemoryCopy(VOID* Destination,CONST VOID* Source,UINTN Count);
VOID*       ESTR_MemorySet(VOID* Destination, INT32 FillChar,UINTN Count);
INT32       ESTR_MemoryCompare(VOID* Buffer1,VOID* Buffer2,UINTN Count);

#endif
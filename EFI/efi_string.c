#include"efi_string.h"
#include"efi.h"

UINT64 ESTR_StringLength(CHAR16* String){
    UINT64 Length = 0;
    while(String[Length] != '\0'){
        Length++;
    }
    return Length;
}

INT32 ESTR_StringEquals(CHAR16* String1,CHAR16* String2){
    UINT64 StrLength1 = ESTR_StringLength(String1);
    UINT64 StrLength2 = ESTR_StringLength(String2);
    
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wgnu-statement-expression-from-macro-expansion"

    return ESTR_MemoryCompare(String1,String2,min(StrLength1,StrLength2));

    #pragma GCC diagnostic pop
}

BOOLEAN ESTR_CharacterEquals(CHAR16 c1,CHAR16 c2){
    if(c1 == c2) 
        return true;
    return false;
}

CHAR16 ESTR_PeekAhead(CHAR16* String){
    return *(String+1);
}

VOID* ESTR_MemoryCopy(VOID* Destination,CONST VOID* Source,UINTN Count){
    CHAR8* Dest = (CHAR8*)Destination;
    CHAR8* Src = (CHAR8*)Source;
    
    for(UINTN Index = 0 ; Index < Count ; ++Index){
        Dest[Index] = Src[Index];
    }
    return Destination;
}

VOID* ESTR_MemorySet(VOID* Destination, INT32 SetWith,UINTN Count){
    INT32* Dest = (INT32*)Destination;

    for(UINTN Index = 0; Index < Count ; ++Index){
        Dest[Index]  = SetWith;
    }
    return Destination;
}

INT32 ESTR_MemoryCompare(VOID* base1,VOID* base2,UINTN Limit){
    for(UINTN Index = 0 ; Index < Limit ; ++Index){
        if ((*(((unsigned char*)base1)+Index)) > (*(((unsigned char*)base2)+Index))){
            return 1;
        }
        else if(((*(((unsigned char*)base1)+Index)) < (*(((unsigned char*)base2)+Index)))){
            return -1;
        }
        continue;
    }
    return 0;
}

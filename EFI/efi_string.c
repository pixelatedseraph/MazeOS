#include"efi_string.h"

UINT64 ESTR_StringLength(CHAR16* String){
    UINT64 Length = 0;
    while(String[Length] != '\0'){
        Length++;
    }
    return Length;
}

BOOLEAN ESTR_StringEquals(CHAR16* String1,CHAR16* String2){
    UINT64 Length;
    if((Length= ESTR_StringLength(String1))!= ESTR_StringLength(String2)){
        return false;
    }

    UINT64 Counter = 0;
    while(*String1++ == *String2++){
        Counter++;
    }
    if(Counter < Length){
        return false;
    }
    return true;
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
    for(UINTN Index = 0 ; Index < Count ; ++Index){
        *(((UINT16*)Destination)+Index) = *(((UINT16*)Source)+Index);
    }
    return Destination;
}
VOID* ESTR_MemorySet(VOID* Destination, INT32 FillChar,UINTN Count){
    for(UINTN Index = 0; Index < Count ; ++Index){
        *(((UINT16*)Destination)+Index) = (CHAR16)FillChar;
    }
    return Destination;
}

//TODO
INT32 ESTR_MemoryCompare(VOID* Buffer1,VOID* Buffer2,UINTN Count){
    for(UINTN Index = 0; Index < Count ; ++Index){
    }
}
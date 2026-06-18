#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Types.h"
#include"wchar.h"


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

void print_hex(void* base,uint32_t limit){
    //printf("0x ");
    for(uint32_t i = 0; i< limit ; ++i){
        printf("%02X ",*(((unsigned char*)base)+i));
    }
    printf("\n");
}



int main(){
    typedef struct Foo{
        INT16 a;
        INT32 b;
        INT64 c;
        UINT16 d;  
        UINT32 e;  
        UINT64 f;
        
        CHAR8  g;
        CHAR16 h;

        CHAR8*  normalStr;
        CHAR16* wStr;
    }Foo;

    char* buff = malloc(64);
    ESTR_MemoryCopy(buff,"Hello World",strlen("Hello World")+1); 

    CHAR16* wide = malloc(sizeof(CHAR16) * 64);
    ESTR_MemoryCopy(wide,L"WelcomeTOtEST",strlen("WelcomeTOtEST")+1);

    Foo f1 = {.a = 3010,.b = -487784,.c= 263569238,
              .d = 7634,.e = 5122681,.f = 90764576368,
              .g = '!', .h = u'M',.normalStr = buff, .wStr = wide };
    Foo f2 ;

    ESTR_MemoryCopy(&f2,&f1,sizeof(f1));
    //memcpy(&f2,&f1,sizeof(f1));

    print_hex(&f1,sizeof(f1));

    /*printf("%d %d %ld\n",f2.a,f2.b,f2.c);
    printf("%d %d %ld\n",f2.d,f2.e,f2.f);
    printf("%c %c\n",f2.g,f2.h);
    printf("%s \n",f2.normalStr);*/
    f2.a = -102;
    print_hex(&f2,sizeof(f2));
   
    printf("%d %d\n",ESTR_MemoryCompare(&f1,&f2,sizeof f1),memcmp(&f1,&f2,sizeof f1));

    int* blk = malloc(4*10);
    ESTR_MemorySet(blk,42,10);

    for(int i = 0 ; i < 10 ; ++i){
        printf("%d ",blk[i]);
    }
    printf("\n");

    free(buff);
    free(wide);
    free(blk);
    return 0;
}
#include<stddef.h>
#include<stdarg.h>
#include"efi.h"
#include"efi_string.h"

#define loop while(1)

EFI_SYSTEM_TABLE* GLB_SystemTable;


VOID Print(CHAR16* String){
     GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,String);
}

#define Println(...) _Println(__VA_ARGS__,ESTR_SENTINEL_STRING)

VOID _Println(CHAR16* String,...){
     va_list ap;
     va_start(ap,String);     
     Print(String);
     CHAR16* TmpString = va_arg(ap,CHAR16*);
     while(!ESTR_StringEquals(TmpString,ESTR_SENTINEL_STRING)){
          Print(TmpString);
          Print(L" ");
          TmpString = va_arg(ap,CHAR16*);
     }
     Print(L"\r\n");
}

//TODO
UINT64 Printf(CHAR16* fmt,...){
     UINT64 Length;

     va_list ap;
     

     for(va_start(ap,fmt); *fmt != '\0'; ++fmt){
          //%d ->INT64
          //Printf(L"Hello World: %d %s",5,"Hey"); -> Printf(L"Hello World: " + L"5"+ L" " +L"Hey" )
          if(ESTR_CharacterEquals(*fmt,L'%') && (ESTR_PeekAhead(fmt) == L'd'))  {
               
          } 
          //%u -> UINT64
          if(ESTR_CharacterEquals(*fmt,L'%') && (ESTR_PeekAhead(fmt) == L'u'))  {} 
          //%s -> CHAR16*
          if(ESTR_CharacterEquals(*fmt,L'%') && (ESTR_PeekAhead(fmt) == L's'))  {} 
          //%x  -> Hexadecimals/Addresses
          if(ESTR_CharacterEquals(*fmt,L'%') && (ESTR_PeekAhead(fmt) == L's'))  {} 

     }
     return Length;
}


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle,EFI_SYSTEM_TABLE* SystemTable){

     (void)ImageHandle;
     GLB_SystemTable = SystemTable;

     //Reset Console Output 
     //SystemTable->ConOut->Reset(SystemTable->ConOut,false);
     //Clears the screen
     //SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
     //Writes to output device
     SystemTable->ConOut->SetAttribute(SystemTable->ConOut,EFI_TEXT_ATTR(EFI_WHITE,EFI_RED));
     Print(L"Hello ");

   
     Println(L"Welcome To Verus Bootloader for UEFI ",L"Its so Cozy Haha");
     Println(L"All Rights Resrved to Mazeed ",L" Under GPLV3 ig idk");

     VOID* HeapBlk;


     EFI_STATUS Returncode = SystemTable->BootServices->AllocatePool(EfiLoaderData,1024,&HeapBlk);
     if(Returncode != EFI_SUCCESS){
          Print(L"Heap Allocation Failed\r\n");
          goto exit;
     }

     *((CHAR16*)HeapBlk)     =  L'w';
     *(((CHAR16*)HeapBlk)+1) =  L'a';
     *(((CHAR16*)HeapBlk)+2) =  L'r';
     *(((CHAR16*)HeapBlk)+3) =  L'\0';

     Print((CHAR16*)HeapBlk);


     SystemTable->BootServices->FreePool(HeapBlk);

     exit:
     loop{}
     return EFI_SUCCESS;
}


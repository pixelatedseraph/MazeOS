#include"efi.h"
#include<stddef.h>


#define loop while(1)

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle,EFI_SYSTEM_TABLE* SystemTable){

     (void)ImageHandle;
     //Reset Console Output 
     //SystemTable->ConOut->Reset(SystemTable->ConOut,false);
     //Clears the screen
     //SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
     //Writes to output device
     SystemTable->ConOut->OutputString(SystemTable->ConOut,L"Hello UEFI world from C!\r\n");

     loop{}
     return EFI_SUCCESS;
}


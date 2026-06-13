#include <efi.h>
#include <efilib.h>

extern "C"
EFI_STATUS
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->ClearScreen(
        SystemTable->ConOut
    );


    SystemTable->ConOut->OutputString(
        SystemTable->ConOut,
        (CHAR16*)L"MazeOS is 64 bit NOW!\r\n"
    );

    for (;;);

    return EFI_SUCCESS;
}
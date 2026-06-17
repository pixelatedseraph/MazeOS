#include"efi.h"
#include"efi_glb.h"
#include"efi_lib.h"

VOID* EFI_Malloc(UINTN Size){
    VOID* HeapBlk;
    EFI_STATUS AllocationStatus = GLB_SystemTable->BootServices->AllocatePool(EfiLoaderData,Size,&HeapBlk);

    if(AllocationStatus != EFI_SUCCESS){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[BootServiceError]: The Firmware didnt successfully allocate required size\r\n");
        return nullptr;
    }
    return HeapBlk;
}

VOID EFI_Free(VOID* Ptr){
    if(Ptr == nullptr){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[LibraryServiceError]: Erroneous pointer passed to free\r\n");
        return;
    }
    GLB_SystemTable->BootServices->FreePool(Ptr);
}
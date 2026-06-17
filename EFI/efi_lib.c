#include"efi.h"
#include"efi_glb.h"
#include"efi_lib.h"
#include"efi_string.h"

VOID* EFI_Malloc(UINTN Size){
    VOID* HeapBlk;
    EFI_STATUS AllocationStatus = GLB_SystemTable->BootServices->AllocatePool(EfiLoaderData,Size,&HeapBlk);

    if(AllocationStatus != EFI_SUCCESS){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[BootServiceError]: The Firmware didnt successfully allocate required size\r\n");
        return nullptr;
    }
    return HeapBlk;
}


VOID* EFI_Calloc(UINTN Count,UINTN Size){
    VOID* HeapBlk = EFI_Malloc(Size * Count);
    if(HeapBlk == nullptr){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[LibraryServiceError]: Call to 'EFI_Calloc' failed as the internal allocator threw a 'BootServiceError'\r\n");
        return HeapBlk;
    }
    return ESTR_MemorySet(HeapBlk,0,Count);
}

//TODO
VOID* EFI_Realloc(VOID* Ptr,UINTN NewSize){
    if(Ptr == nullptr){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[LibraryServiceError]: Erroneous pointer passed to 'EFI_Realloc'\r\n");
        return nullptr;
    }
    VOID* HeapBlk = EFI_Malloc(NewSize);
}



VOID EFI_Free(VOID* Ptr){
    if(Ptr == nullptr){
        GLB_SystemTable->ConOut->OutputString(GLB_SystemTable->ConOut,L"[LibraryServiceError]: Erroneous pointer passed to EFI_Free\r\n");
        return;
    }
    GLB_SystemTable->BootServices->FreePool(Ptr);
}
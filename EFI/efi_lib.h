/*
 * efilib.h
 *
 * stdlib.h equivalent for UEFI applications providing abstractions for memory allocations on heap
 *
 * Author: Mazeed A.
 * SPDX-License-Identifier: GPLv3
 */

#ifndef __EFI_LIB_H
#define __EFI_LIB_H

#include"efi.h"
#include"efi_glb.h"

VOID* EFI_Malloc(UINTN Size);

VOID EFI_Free(VOID* Ptr);

#endif

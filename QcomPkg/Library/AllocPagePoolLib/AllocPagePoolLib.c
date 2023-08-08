/** @file AllocPagePool.c

  Implementation of page allocator in SEC

  Copyright (c) 2016,2018 Qualcomm Technologies Inc. All rights reserved. 

**/

/*=============================================================================
                              EDIT HISTORY

 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 12/09/16   bh      Adjust initial page pool allocation for ASLR
 07/26/16   vk      Initial revision
=============================================================================*/

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/AslrLib.h>

VOID *
EFIAPI
AllocatePages (IN UINTN Pages); 

extern
VOID *
EFIAPI
_AllocatePages (IN UINTN Pages); 


typedef enum PoolOperation {
  GET_PAGEPOOL_INFO,
  SET_PAGEPOOL, 
  SET_PAGEPOOL_ALLOC,
  SET_PAGEPOOL_FREE
} PagePoolOperationType;

STATIC
EFI_STATUS
PagePoolOperation (PagePoolOperationType Operation, VOID **Buffer, UINTN *PageCount)
{
  EFI_STATUS Status = EFI_INVALID_PARAMETER;
  
  STATIC VOID* PagePoolBuffer         = NULL;
  STATIC UINTN PagePoolAllocatedCount = 0;
  STATIC UINTN PagePoolSize           = 0;

  VOID *pCurrentAllocation            = NULL;
  UINTN CurrentAllocReqCount          = 0;

  if ((Buffer == NULL) || (PageCount == NULL))
  {
    ASSERT (FALSE);
    return EFI_INVALID_PARAMETER;
  }

  if ( (Operation == GET_PAGEPOOL_INFO) && (PagePoolBuffer == NULL) )
    return EFI_NOT_READY;

  switch (Operation)
  {
    case SET_PAGEPOOL:
      PagePoolBuffer = *Buffer;
      PagePoolAllocatedCount = 0;
      PagePoolSize = *PageCount;
      Status = EFI_SUCCESS;	    
      break;

    case SET_PAGEPOOL_FREE:
      ASSERT (PagePoolAllocatedCount >= (*PageCount));
      if (PagePoolAllocatedCount >= (*PageCount))
      {
        VOID* BufferEnd, *PoolEnd;

        PoolEnd = (VOID*)((UINTN)PagePoolBuffer + (EFI_PAGE_SIZE * PagePoolAllocatedCount));
        BufferEnd = (VOID*)(((UINTN)(*Buffer)) + (EFI_PAGE_SIZE * (*PageCount)));

        if (PoolEnd == BufferEnd)
          PagePoolAllocatedCount -= (*PageCount);

        Status = EFI_SUCCESS;	    
      }
      break;

    case SET_PAGEPOOL_ALLOC:
      CurrentAllocReqCount = *PageCount;
      
      /* Check if we have space in current buffer for allocation */
      ASSERT ( (PagePoolAllocatedCount + CurrentAllocReqCount) < PagePoolSize);
      if ( (PagePoolAllocatedCount + CurrentAllocReqCount) > PagePoolSize) 
      {
        Status = EFI_OUT_OF_RESOURCES;	    
        break;	      
      }

      /* Locate currently allocated location in pool */	      
      pCurrentAllocation = (VOID*)((UINTN)PagePoolBuffer + (EFI_PAGE_SIZE * PagePoolAllocatedCount));

      /* Update to reflect new allocation */
      PagePoolAllocatedCount += CurrentAllocReqCount;

      /* Return current allocation pointer */
      *Buffer = pCurrentAllocation;
      Status = EFI_SUCCESS;
      break;

    case GET_PAGEPOOL_INFO:  
      *Buffer = PagePoolBuffer;
      *PageCount = PagePoolAllocatedCount;    
      Status = EFI_SUCCESS;
      break;

    default:
      Status = EFI_INVALID_PARAMETER;
      ASSERT(FALSE);
      break;
  }

  return Status;
}

EFI_STATUS
ReInitPagePoolBuffer (UINTN PoolPageCount)
{
  EFI_STATUS Status;
  UINTN NumPages = PoolPageCount;
  VOID* pPagePool = NULL;
  
  ASSERT (NumPages != 0);
    
  /* Get new buffer from bigger pool */
  pPagePool = _AllocatePages (NumPages);
  ASSERT (pPagePool != NULL);
  if (pPagePool == NULL)
    return EFI_OUT_OF_RESOURCES;

  /* Set new buffer as pool with zero bytes allocated from new buffer */
  Status = PagePoolOperation (SET_PAGEPOOL, &pPagePool, &NumPages);
  ASSERT (Status == EFI_SUCCESS);

  return Status;	
}

#define DEBUG_PAGE_ALLOCS      0

VOID *
EFIAPI
AllocatePages (IN UINTN Pages)
{
#ifdef ENABLE_ASLR
  /* ASLR will use up heaps space, adjust the allocation accordingly */
  #define PAGE_POOL_SIZE_SEC       (SIZE_512KB - (((0x1 << ASLR_HEAP_RNG_BITS)-1)*EFI_PAGE_SIZE))
#else
  #define PAGE_POOL_SIZE_SEC       (SIZE_512KB)
#endif

  EFI_STATUS Status;
  UINTN PageCount = 0;
  VOID* pPagePool = NULL;

  ASSERT (Pages != 0);

  Status = PagePoolOperation (GET_PAGEPOOL_INFO, &pPagePool, &PageCount);
  if (Status == EFI_NOT_READY)
  {
    /* Ensure first allocation will fit in limited range, and handle if ASSERT is disabled  */
    ASSERT (PAGE_POOL_SIZE_SEC > (Pages * EFI_PAGE_SIZE));
    if (PAGE_POOL_SIZE_SEC < (Pages * EFI_PAGE_SIZE))
      return NULL;  

    /* Allocate big chunk during first init */
    PageCount = PAGE_POOL_SIZE_SEC / EFI_PAGE_SIZE;
    pPagePool = _AllocatePages (PageCount);
    ASSERT (pPagePool != NULL);
    if (pPagePool == NULL)
      return NULL;

    /* Set this as new page pool buffer*/
    Status = PagePoolOperation (SET_PAGEPOOL, &pPagePool, &PageCount);
    ASSERT (Status == EFI_SUCCESS);

    /* Update pool buffer for current allocation */
    PageCount = Pages;
    Status = PagePoolOperation (SET_PAGEPOOL_ALLOC, &pPagePool, &PageCount);
    ASSERT (Status == EFI_SUCCESS);

    if (DEBUG_PAGE_ALLOCS && (Pages >= 0x20))
      DEBUG ((EFI_D_ERROR, "Page Alloc  %X   %X\n", pPagePool, Pages));

    return pPagePool;
  }
  else
  {
    Status = PagePoolOperation (GET_PAGEPOOL_INFO, &pPagePool, &PageCount);
    ASSERT (Status == EFI_SUCCESS);

    PageCount = Pages;
    /* Smaller allocations from reserved pool */
    Status = PagePoolOperation (SET_PAGEPOOL_ALLOC, &pPagePool, &PageCount);
    ASSERT (Status == EFI_SUCCESS);

    if (DEBUG_PAGE_ALLOCS && (Pages >= 0x20))
      DEBUG ((EFI_D_ERROR, "Page Alloc  %X   %X\n", pPagePool, Pages));

    return pPagePool;
  }

  ASSERT(FALSE);

  return NULL;
}

VOID
EFIAPI
FreePages (
  IN VOID   *Buffer,
  IN UINTN  Pages
  )
{
  UINTN FreeCount;
  VOID* BufferPtr;

  FreeCount = Pages;
  BufferPtr = Buffer;

  PagePoolOperation (SET_PAGEPOOL_FREE, &BufferPtr, &FreeCount);
}


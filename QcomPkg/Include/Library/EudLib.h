/**
  @file  EudLib.h
  @brief Header for EUD Library.
*/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 08/14/19   aj      Check-in
 07/18/19   dt      Created.

=============================================================================*/
#ifndef __EUDLIB_H__
#define __EUDLIB_H__

/*
 * Handler for EUD Enable Protocol
 */
EFI_STATUS Eud_Enable(VOID);

/*
 * Handler for EUD Disable Protocol
 */
EFI_STATUS Eud_Disable(VOID);

/*
 * Handler to read EUD status 
 */
EFI_STATUS Eud_Read(UINTN *);

#endif  /* __EUDLIB_H__ */

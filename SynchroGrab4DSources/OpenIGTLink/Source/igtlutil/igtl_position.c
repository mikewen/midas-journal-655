/*=========================================================================

  Program:   Open ITK Link Library
  Module:    $HeadURL: http://svn.na-mic.org/NAMICSandBox/trunk/OpenIGTLink/Source/igtlutil/igtl_position.c $
  Language:  C
  Date:      $Date: 2008-12-22 19:05:42 -0500 (Mon, 22 Dec 2008) $
  Version:   $Revision: 3460 $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include <string.h>
#include "igtl_position.h"
#include "igtl_util.h"

#include <stdio.h>


void igtl_export igtl_position_convert_byte_order(igtl_position* pos)
{

  int i;
  igtl_uint32 tmp[4];

  if (igtl_is_little_endian())
    {
    /* position */
    memcpy((void*)tmp, (void*)(pos->position), sizeof(igtl_float32)*3);
    tmp[0]  = BYTE_SWAP_INT32(tmp[0]);
    tmp[1]  = BYTE_SWAP_INT32(tmp[1]);
    tmp[2]  = BYTE_SWAP_INT32(tmp[2]);
    memcpy((void*)(pos->position), (void*)tmp, sizeof(igtl_float32)*3);

    /* quaternion */
    memcpy((void*)tmp, (void*)(pos->quaternion), sizeof(igtl_float32)*4);
    tmp[0]  = BYTE_SWAP_INT32(tmp[0]);
    tmp[1]  = BYTE_SWAP_INT32(tmp[1]);
    tmp[2]  = BYTE_SWAP_INT32(tmp[2]);
    tmp[3]  = BYTE_SWAP_INT32(tmp[3]);
    memcpy((void*)(pos->quaternion), (void*)tmp, sizeof(igtl_float32)*4);
    }
}


igtl_uint64 igtl_export igtl_position_get_crc(igtl_position* pos)
{

  igtl_uint64 crc = crc64(0, 0, 0);

  crc = crc64((unsigned char*)pos, IGTL_POSITION_MESSAGE_DEFAULT_SIZE, crc);

  return crc;
}

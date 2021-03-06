/*=========================================================================

  Program:   Open ITK Link Library
  Module:    $HeadURL: http://svn.na-mic.org/NAMICSandBox/trunk/OpenIGTLink/Source/igtlutil/igtl_win32header.h $
  Language:  C
  Date:      $Date: 2008-12-22 19:05:42 -0500 (Mon, 22 Dec 2008) $
  Version:   $Revision: 3460 $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __IGTL_WIN32HEADER_H
#define __IGTL_WIN32HEADER_H

#include "igtl_typeconfig.h"

#if (defined(_WIN32) || defined(WIN32)) && !defined(IGTLSTATIC) 
# ifdef IGTLCommon_EXPORTS
#  define igtl_export __declspec(dllexport)
# else
#  define igtl_export __declspec(dllimport)
# endif  /* igtl_common_exports */
#else
/* unix needs nothing */
#define igtl_export
#endif


#endif /*__IGTL_WIN32HEADER_H*/

/*##################################################################################
#  Copyright (C) 2019 - TerraProcess Team - Brazil.
#
#  This file is part of the TerraProcess - A GIS application used for
#  generating scripts for data processing using graphic language.
#
#  TerraProcess is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published
#  by the Free Software Foundation, either version 3 of the License,
#  or (at your option) any later version.
#
#  TerraProcess is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with TerraProcess. See COPYING. If not, write to
#  TerraProcess Team. See README file for more information.
##################################################################################*/

/*!
  \file terraprocess/src/process/Config.h

  \brief Configuration flags for TerraProcess module lib.
*/


#ifndef __TERRAPROCESS_PROCESS_CONFIG__
#define __TERRAPROCESS_PROCESS_CONFIG__
 
#ifdef WIN32
  #ifdef _MSC_VER 
    #pragma warning( disable : 4251 )
  #endif

  #ifdef TERRAPROCESSSTATIC
    #define TERRAPROCESSEXPORT                          // Don't need to export/import... it is a static library
  #elif TERRAPROCESSDLL
    #define TERRAPROCESSEXPORT  __declspec(dllexport)   // export DLL information
  #else
    #define TERRAPROCESSEXPORT  __declspec(dllimport)   // import DLL information
  #endif 
#else
  #define TERRAPROCESSEXPORT
#endif

#endif  // __TERRAPROCESS_PROCESS_CONFIG__


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
  \file AbstractType.h
   
  \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_TYPE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_TYPE__

#include "src/process_qt/Config.h"

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
      \brief Enum TdkAbstractComponentType. This is the enumeration of the components types
      */
      enum Align
      {
        TPTopLeft,
        TPTopRight,
        TPLowerLeft,
        TPLowerRight,
        TPCenter,
        TPRight,
        TPLeft,
        TPTop,
        TPLower,
        TPNoneSide
      };

      /*!
      \brief Enum EnumTypeFlags. This is the type of the EnumTypes.
      */
      enum TERRAPROCESSQTEXPORT EnumTypeFlags
      {
        EnumNone = 0,
        EnumCreate = 1,
        EnumTool = 2,
        EnumAction = 3,
        EnumDialog = 4
      };
    }
  }
}

#endif // __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_TYPE__

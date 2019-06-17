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
\file DataTypes.h

\brief This file defines the enum and typedefs for all basic types in the module

\ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPES__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPES__

#include <terralib/datatype/Enums.h>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      enum class Types
      {
        BOOLEAN_TYPE = te::dt::LAST_COMMON_DATATYPE_CODE + 100
        , COLOR_TYPE
        , DOUBLE_TYPE
        , ENVELOPE_TYPE
        , FONT_TYPE
        , GEOMETRY_TYPE
        , INT_TYPE
        , STRING_TYPE
        , STRING_LIST_TYPE
        , STRING_MATRIX_TYPE
        , LAYER_LIST_TYPE
      };
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPES__

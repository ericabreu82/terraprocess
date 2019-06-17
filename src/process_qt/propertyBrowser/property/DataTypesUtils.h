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
\file DataTypesUtils.h

\brief This file defines the enum and typedefs for all basic types in the module

\ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPEUTILS__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPEUTILS__ 

#include "src/process_qt/propertyBrowser/property/Data.h"
#include "src/process_qt/propertyBrowser/property/TypeManager.h"

//Terralib
#include <terralib/common/Exception.h>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      void clearTypes();

      template<typename T>
      te::dt::AbstractData* CreateData(const T& value)
      {
        te::dt::AbstractData* abstractData = new Data<T>(value, TypeManager::getInstance());
        return abstractData;
      }

      template<typename T>
      const T& GetValueAs(const te::dt::AbstractData* absData)
      {
        const Data<T>* castData = dynamic_cast<const Data<T>*>(absData);
        if (castData == 0)
        {
          throw te::common::Exception("Property: invalid type cast");
        }

        return castData->getValue();
      }
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPEUTILS__ 

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
  \file Enums.h
   
   \brief Singleton class responsible for keeping active objects of Enum while the plugin is loaded in memory 
          and make them available for access anywhere in the plugin or module.
      Ex .: Enum for data type, enum for object type, enum for mode type, enum for template type, etc.

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUMS__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUMS__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/EnumType.h"
#include "src/process_qt/propertyBrowser/enum/EnumDataType.h"

//TerraLib
#include <terralib/common/Singleton.h>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
        \brief Singleton class responsible for keeping active objects of Enum while the plugin is loaded in memory
               and make them available for access anywhere in the plugin or module.
          Ex .: Enum for data type, enum for object type, enum for mode type, enum for template type, etc.

        \ingroup propertyBrowser

        \sa te::common::Singleton
      */
      class TERRAPROCESSQTEXPORT Enums : public te::common::Singleton<Enums>
      {
        friend class te::common::Singleton<Enums>;

      public:

        /*!
          \brief Destructor
        */
        virtual ~Enums();

        /*!
          \brief Change data type enumeration.

          \param type data type enumeration
        */
        virtual void setEnumDataType(EnumDataType* type);

        /*!
          \brief Returns data type enumeration.

          \return data type enumeration
        */
        virtual EnumDataType* getEnumDataType();
        
      protected:

        /*!
          \brief Constructor
        */
        Enums();

      protected:

        EnumDataType* m_dataType; //!< data type enumeration

      private:

        /*!
        \brief Copy constructor not allowed.

        \param rhs The right-hand-side copy that would be used to copy from.
        */
        Enums(const Enums& rhs);

        /*!
        \brief Assignment operator not allowed.

        \param rhs The right-hand-side copy that would be used to copy from.

        \return A reference to this object.
        */
        Enums& operator=(const Enums& rhs);
      };
    }
  }
}

#endif

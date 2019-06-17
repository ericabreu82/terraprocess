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
  \file EnumType.h
   
  \brief Class that represents the value of an enumeration. An enumeration is made of "1..n" objects EnumType.

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_TYPE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_TYPE__

// TerraLib
#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/AbstractType.h"

// STL
#include <string>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class AbstractEnum;
      /*!
        \brief Class that represents the value of an enumeration. An enumeration is made of "1..n" objects EnumType.

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT EnumType
      {
      public:

        /*!
         \brief Constructor. Name parameter will be uppercase.

         \param id numeric value assigned
         \param name
        */
        EnumType(int id, const std::string& name, AbstractEnum* type);

        /*!
         \brief Destructor
        */
        virtual ~EnumType();

        /*!
          \brief Returns numeric value assigned

          \return numeric value assigned
        */
        int getId();

        /*!
          \brief Returns name

          \return name
        */
        std::string getName();

        /*!
          \brief Change name. Name parameter will be uppercase.

          \return new name
        */
        void setName(const std::string& name);

        /*!
          \brief Returns label

          \return label
        */
        std::string getLabel();

        /*!
          \brief Change label

          \return new label
        */
        void setLabel(const std::string& label);

        /*!
          \brief Returns enum type

          \return enum type
        */
        AbstractEnum* getParent();

        /*!
          \brief Returns enum type

          \return enum type
        */
        tr::processQt::propertyBrowser::EnumTypeFlags getType();

        /*!
          \brief Sets enum type

          \return enum type
        */
        void setType(tr::processQt::propertyBrowser::EnumTypeFlags type);

      protected:

        int         m_id; //!< numeric value assigned
        std::string m_name; //!< name
        std::string m_label; //!< label
        AbstractEnum* m_parent;
        tr::processQt::propertyBrowser::EnumTypeFlags m_type;
      };
    }
  }
}

#endif

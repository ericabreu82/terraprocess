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

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_ENUM__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_ENUM__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/EnumType.h"

// STL
#include <string>
#include <vector>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
        \brief Abstract class to represent an enumeration.

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT AbstractEnum
      {
      public:

        /*!
          \brief Constructor
        */
        AbstractEnum();

        /*!
          \brief Destructor
        */
        virtual ~AbstractEnum();

        /*!
          \brief Searching for a value of the enumeration by id

          \param enumId id
          \return value found in the enumeration or null
        */
        virtual EnumType* getEnum(int enumId) const;

        /*!
          \brief Searching for an enumeration value by name

          \param name
          \return value found in the enumeration or null
        */
        virtual EnumType* getEnum(const std::string& name) const;

        /*!
          \brief Searching for a max value of the id

          \return -1 if no found, otherwise the id
        */
        virtual int maxId();

        /*!
          \brief Searching for a min value of the id

          \return -1 if no found, otherwise the id
        */
        virtual int minId();

        virtual int size();

      protected:

        /*!
          \brief Creates the enumeration values and adds the list
        */
        virtual EnumType* createEnum(std::string name, AbstractEnum* type, std::string label = "");

        /*!
        \brief Creates the enumeration values and adds the list
        */
        virtual EnumType* createEnum(int id, const std::string& name, AbstractEnum* type, const std::string& label = "");

      protected:

        std::vector<EnumType*> m_enums; //!< list of enumeration values
      };
    }
  }
}

#endif

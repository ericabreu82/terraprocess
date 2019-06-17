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
  \file EnumDataType.h
   
  \brief Class to represent a data type enumeration. Ex.: int, double, bool, te::color::RGBAColor (color), etc.

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATATYPE__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/AbstractEnum.h"

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class EnumType;

      /*!
        \brief Class to represent a data type enumeration. Ex.: int, double, bool, te::color::RGBAColor (color), etc.

        \ingroup propertyBrowser

        \sa tr::processQt::propertyBrowser::AbstractEnum
      */
      class TERRAPROCESSQTEXPORT EnumDataType : public AbstractEnum
      {
      public:

        /*!
          \brief Constructor
        */
        EnumDataType();

        /*!
          \brief Destructor
        */
        virtual ~EnumDataType();

        /*!
          \brief Returns value that represents type none belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeNone() const;

        /*!
          \brief Returns value that represents type integer belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeInt() const;

        /*!
          \brief Returns value that represents type double belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeDouble() const;

        /*!
          \brief Returns value that represents type long belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeLong() const;

        /*!
          \brief Returns value that represents type float belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeFloat() const;

        /*!
          \brief Returns value that represents type string belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeString() const;

        /*!
          \brief Returns value that represents type bool belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeBool() const;

        /*!
          \brief Returns value that represents type te::color::RGBAColor** (color) belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeColor() const;
        
        /*!
          \brief Returns value that represents type StringList (string) belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeStringList() const;

        /*!
          \brief Returns value that represents type Font belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeFont() const;

        /*!
          \brief Returns value that represents type Envelope belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeEnvelope() const;

        /*!
          \brief Returns value that represents type image (string) belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeImage() const;
        
        /*!
          \brief Returns value that represents type Group (string) belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeGroup() const;

        /*!
          \brief Returns value that represents type string vector (std::vector<std::string>) belonging to enumeration

          \return enum value
        */
        virtual EnumType* getDataTypeStringVector() const;

        /*!
        \brief Returns value that represents a vector of string vector (std::vector< std::vector<std::string> >) belonging to enumeration

        \return enum value
        */
        virtual EnumType* getDataTypeStringMatrix() const;
        
        /*!
          \brief Returns shared pointer of the type te::gm::Geometry belonging to enumeration.

          \return enum value
        */
        virtual EnumType* getDataTypeGeometry() const;

        /*!
        \brief Returns pointer to item observer type belonging to enumeration.

        \return enum value
        */
        virtual EnumType* getDataTypeItemObserver() const;

        /*!
        \brief Returns pointer to group properties type belonging to enumeration.

        \return enum value
        */
        virtual EnumType* getDataTypeGroupProperties() const;
        
        /*!
        \brief Returns value that represents type file path (string) belonging to enumeration

        \return enum value
        */
        virtual EnumType* getDataTypePath() const;
        
      protected:

        /*!
          \brief Reimplemented from AbstractEnum
        */
        void init();

      protected:

        EnumType* m_dataTypeNone; //!< value that represents type none belonging to enumeration
        EnumType* m_dataTypeInt; //!< value that represents type integer belonging to enumeration
        EnumType* m_dataTypeDouble; //!< value that represents type double belonging to enumeration
        EnumType* m_dataTypeLong; //!< value that represents type long belonging to enumeration
        EnumType* m_dataTypeFloat; //!< value that represents type float belonging to enumeration
        EnumType* m_dataTypeString; //!< value that represents type string belonging to enumeration
        EnumType* m_dataTypeBool; //!< value that represents type bool belonging to enumeration
        EnumType* m_dataTypeColor; //!< value that represents type te::color::RGBAColor** (color) belonging to enumeration
        EnumType* m_dataTypeStringList; //!< value that represents type StringList (string) belonging to enumeration.
        EnumType* m_dataTypeFont; //!< value that represents type Font belonging to enumeration
        EnumType* m_dataTypeEnvelope; //!< value that represents type Envelope belonging to enumeration
        EnumType* m_dataTypeImage; //!< value that represents type image (string) belonging to enumeration
        EnumType* m_dataTypeGroup; //!< value that represents type Group (string) belonging to enumeration
        EnumType* m_dataTypeStringVector; //!< value that represents type string vector (std::vector<std::string>) belonging to enumeration
        EnumType* m_dataTypeStringMatrix; //!< value that represents a vector of string vector (std::vector< std::vector<std::string> >) belonging to enumeration     
        EnumType* m_dataTypeGeometry; //!< shared pointer to te::gm::Geometry belonging to enumeration
        EnumType* m_dataTypeItemObserver; //!< value that represents type item observer to belonging to enumeration
        EnumType* m_dataTypeGroupProperties; //!< value that represents type group properties to  belonging to enumeration
        EnumType* m_dataTypePath; //!< value that represents type File Path (string) belonging to enumeration
      };
    }
  }
}

#endif




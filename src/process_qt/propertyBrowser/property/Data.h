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

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATA__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATA__ 

#include "src/process_qt/propertyBrowser/property/TypeManager.h"
#include "src/process_qt/propertyBrowser/property/DataTypes.h"

//terralib
#include <terralib/common/Exception.h>
#include <terralib/datatype/AbstractData.h>
#include <terralib/datatype/DataTypeConverter.h>

//STL
#include <memory>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      template<typename T> class Data : public te::dt::AbstractData
      {
      public:
        //!< Constructor. The given value will be copied
        Data(const T& value, const TypeManager& typeManager);

        virtual ~Data();

        /*!
        \brief Copy constructor.

        \param rhs The right-hand-side data.
        */
        Data(const Data& rhs);

        /*!
        \brief It returns a clone of this object.

        \return A clone of this object.
        */
        virtual te::dt::AbstractData* clone() const;

        /*!
        \brief It returns the data type code associated to the data value.

        \return The data type code associated to the data value.
        */
        virtual int getTypeCode() const;

        /*!
        \brief It returns the data value in a string notation.

        \return The data value in a string notation.
        */
        virtual std::string toString() const;

        virtual const T& getValue() const;

      protected:

        const Data<T>& operator=(const Data<T>& rhs);

      protected:

        int m_typeCode; //!< The type code associated to this data
        std::unique_ptr<T> m_value; //!< The value of the data
        te::dt::DataTypeConverter m_converterToString;
      };


      template<typename T> Data<T>::Data(const T& value, const TypeManager& typeManager)
        : te::dt::AbstractData()
        , m_typeCode(0)
        , m_value(new T(value))
      {
        m_typeCode = typeManager.getTypeCode<T>();
        m_converterToString = typeManager.getConverter(m_typeCode, (int)tr::processQt::propertyBrowser::Types::STRING_TYPE);
      }

      template<typename T> Data<T>::~Data()
      {

      }

      template<class T> Data<T>::Data(const Data& rhs)
        : te::dt::AbstractData(rhs)
        , m_typeCode(rhs.m_typeCode)
        , m_value(new T(*rhs.m_value))
        , m_converterToString(rhs.m_converterToString)
      {
      }

      template<typename T> te::dt::AbstractData* Data<T>::clone() const
      {
        return new Data(*this);
      }

      template<typename T> int Data<T>::getTypeCode() const
      {
        return m_typeCode;
      }

      template<typename T> std::string Data<T>::toString() const
      {
        if (m_typeCode == (int)tr::processQt::propertyBrowser::Types::STRING_TYPE)
        {
          const Data<std::string>* stringData = dynamic_cast<const Data<std::string>*>(this);
          if (stringData == 0)
          {
            throw te::common::Exception("Data::Invalid type cast");
          }

          return stringData->getValue();
        }

        std::unique_ptr<te::dt::AbstractData> temporaryData(m_converterToString((te::dt::AbstractData*)this));
        Data<std::string>* stringData = dynamic_cast<Data<std::string>*>(temporaryData.get());
        if (stringData == 0)
        {
          throw te::common::Exception("Data::Invalid type cast");
        }

        return stringData->getValue();
      }

      template<typename T> const T& Data<T>::getValue() const
      {
        return *m_value;
      }
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DATA__ 

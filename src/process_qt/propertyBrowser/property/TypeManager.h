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


#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TYPEMANAGER__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TYPEMANAGER__ 

#include "src/process_qt/Config.h"

// TerraLib
#include <terralib/common/Singleton.h>
#include <terralib/datatype/DataTypeConverter.h>
#include <terralib/common/Exception.h>

//STL
#include <map>
#include <string>

namespace te
{
  namespace dt
  {
    class AbstractData;
  }
}

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {

      class TERRAPROCESSQTEXPORT TypeManager : public te::common::Singleton<TypeManager>
      {
        friend class te::common::Singleton<TypeManager>;

      public:

        template <typename T>
        void registerType(int typeCode, const std::string& typeName, const te::dt::DataTypeConverter& converterFromString, const te::dt::DataTypeConverter& converterToString);

        //!< Returns the converted FROM fromTypeCode TO toTypeCode
        const te::dt::DataTypeConverter& getConverter(int fromTypeCode, int toTypeCode) const;

        //!< Converts the given data into the given type code. If there is not a registered converter, throws exception
        te::dt::AbstractData* convertTo(te::dt::AbstractData* data, int toTypeCode) const;

        //!< Returns the typeCode from a given typeName
        int getTypeCode(const std::string& typeName) const;

        //!< Returns the typeCode from a given typeName
        template <typename T>
        int getTypeCode() const;

        //!< Returns the typeName from a given typeCode
        std::string getName(int typeCode) const;

        //!< Clear the local list of types (Doesn't clear DataConverterManager list)
        void clear();

      protected:

        /*! \brief Constructor for singletons is protected. */
        TypeManager();

        /*! \brief Destructor for singletons is protected. */
        virtual ~TypeManager();

        void registerTypeImpl(int typeCode, const std::string& typeName, const std::string& cTypeName, const te::dt::DataTypeConverter& converterFromString, const te::dt::DataTypeConverter& converterToString);

      protected:

        std::map<std::string, int> m_mapTypeNames;
        std::map<int, std::string> m_mapTypeCodes;

        std::map<std::string, std::string> m_mapCTypeNames; //!< Maps the C++ names to the alias given during Type registration <cTypeName, typeName>

      private:

        void registerTypes();
      };

      template <typename T>
      int tr::processQt::propertyBrowser::TypeManager::getTypeCode() const
      {
        std::string cTypeName = typeid(T).name();

        std::map<std::string, std::string>::const_iterator itCTypeName = m_mapCTypeNames.find(cTypeName);
        if (itCTypeName == m_mapCTypeNames.end())
        {
          throw te::common::Exception("TypeManager::Invalid type code");
        }

        std::string typeName = itCTypeName->second;
        return getTypeCode(typeName);
      }

      //implementation of the template function
      template <typename T>
      void tr::processQt::propertyBrowser::TypeManager::registerType(int typeCode, const std::string& typeName, const te::dt::DataTypeConverter& converterFromString, const te::dt::DataTypeConverter& converterToString)
      {
        std::string cTypeName = typeid(T).name();
        registerTypeImpl(typeCode, typeName, cTypeName, converterFromString, converterToString);
      }
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TYPEMANAGER__ 

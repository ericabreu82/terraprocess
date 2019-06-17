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

#include "src/process_qt/propertyBrowser/property/TypeManager.h"

#include "src/process_qt/propertyBrowser/property/DataTypes.h"
#include "src/process_qt/propertyBrowser/property/DataConverters.h"
#include "src/process_qt/propertyBrowser/property/Data.h"
#include "src/process_qt/propertyBrowser/property/Font.h"

//terralib
#include <terralib/color/RGBAColor.h>
#include <terralib/common/Exception.h>
#include <terralib/common/Exception.h>
#include <terralib/datatype/Enums.h>
#include <terralib/datatype/DataConverterManager.h>
#include <terralib/geometry/Envelope.h>
#include <terralib/geometry/Geometry.h>
#include <terralib/maptools/AbstractLayer.h>

// STL
#include <vector>
#include <list>

void tr::processQt::propertyBrowser::TypeManager::registerTypeImpl(int typeCode, const std::string& typeName, const std::string& cTypeName, const te::dt::DataTypeConverter& converterFromString, const te::dt::DataTypeConverter& converterToString)
{
  if (m_mapTypeNames.find(typeName) != m_mapTypeNames.end())
  {
    throw te::common::Exception("TypeManager::Type code already registered");
  }

  if (m_mapTypeCodes.find(typeCode) != m_mapTypeCodes.end())
  {
    throw te::common::Exception("TypeManager::Type name already registered");
  }

  if (m_mapCTypeNames.find(cTypeName) != m_mapCTypeNames.end())
  {
    throw te::common::Exception("TypeManager::Type name already registered");
  }

  m_mapTypeNames[typeName] = typeCode;
  m_mapTypeCodes[typeCode] = typeName;
  m_mapCTypeNames[cTypeName] = typeName;

  //then we register the converters in DataConverterManager
  //as there is not way to check if the converter is already added, we handle the exception

  try
  {
    te::dt::DataConverterManager::getInstance().add((int)tr::processQt::propertyBrowser::Types::STRING_TYPE, typeCode, converterFromString);
  }
  catch (const te::common::Exception&)
  {
  }

  //if the convertion is from type string to type string, we do not need to register it twice
  //we just register the backwards convertion if the types are different
  if (typeCode != (int)tr::processQt::propertyBrowser::Types::STRING_TYPE)
  {
    try
    {
      te::dt::DataConverterManager::getInstance().add(typeCode, (int)tr::processQt::propertyBrowser::Types::STRING_TYPE, converterToString);
    }
    catch (const te::common::Exception&)
    {
    }
  }
}

const te::dt::DataTypeConverter& tr::processQt::propertyBrowser::TypeManager::getConverter(int fromTypeCode, int toTypeCode) const
{
  const te::dt::DataTypeConverter& converter = te::dt::DataConverterManager::getInstance().get(fromTypeCode, toTypeCode);
  return converter;
}

te::dt::AbstractData* tr::processQt::propertyBrowser::TypeManager::convertTo(te::dt::AbstractData* data, int typeCode) const
{
  if (data->getTypeCode() == typeCode)
  {
    return data->clone();
  }

  const te::dt::DataTypeConverter& converter = getConverter(data->getTypeCode(), typeCode);
  te::dt::AbstractData* convertedData = converter(data);
  return convertedData;
}

int tr::processQt::propertyBrowser::TypeManager::getTypeCode(const std::string& typeName) const
{
  std::map<std::string, int>::const_iterator it = m_mapTypeNames.find(typeName);
  if (it == m_mapTypeNames.end())
  {
    throw te::common::Exception("TypeManager::Invalid type code");
  }

  return it->second;
}

std::string tr::processQt::propertyBrowser::TypeManager::getName(int typeCode) const
{
  std::map<int, std::string>::const_iterator it = m_mapTypeCodes.find(typeCode);
  if (it == m_mapTypeCodes.end())
  {
    throw te::common::Exception("TypeManager::Invalid type name");
  }

  return it->second;
}

void tr::processQt::propertyBrowser::TypeManager::clear()
{
  //TODO: Needs to remove from te::dt::DataConverterManager, but it does not have a method to remove.
  m_mapTypeNames.clear();
  m_mapTypeCodes.clear();
  m_mapCTypeNames.clear();
}

//protected constructor
tr::processQt::propertyBrowser::TypeManager::TypeManager()
{
  registerTypes();
}

//protected destructor
tr::processQt::propertyBrowser::TypeManager::~TypeManager()
{

}

void tr::processQt::propertyBrowser::TypeManager::registerTypes()
{
  registerType<bool>((int)tr::processQt::propertyBrowser::Types::BOOLEAN_TYPE, "bool", ConvertStringToBool, ConvertBoolToString);
  registerType<te::color::RGBAColor>((int)tr::processQt::propertyBrowser::Types::COLOR_TYPE, "color", ConvertStringToColor, ConvertColorToString);
  registerType<double>((int)tr::processQt::propertyBrowser::Types::DOUBLE_TYPE, "double", ConvertStringToDouble, ConvertDoubleToString);
  registerType<te::gm::Envelope>((int)tr::processQt::propertyBrowser::Types::ENVELOPE_TYPE, "envelope", ConvertStringToEnvelope, ConvertEnvelopeToString);
  registerType<tr::processQt::propertyBrowser::Font>((int)tr::processQt::propertyBrowser::Types::FONT_TYPE, "font", ConvertStringToFont, ConvertFontToString);
  registerType<te::gm::GeometryShrPtr>((int)tr::processQt::propertyBrowser::Types::GEOMETRY_TYPE, "geometry", ConvertStringToGeometry, ConvertGeometryToString);
  registerType<int>((int)tr::processQt::propertyBrowser::Types::INT_TYPE, "int", ConvertStringToInt, ConvertIntToString);
  registerType<std::string>((int)tr::processQt::propertyBrowser::Types::STRING_TYPE, "string", 0, 0);
  registerType< std::vector<std::string> >((int)tr::processQt::propertyBrowser::Types::STRING_LIST_TYPE, "string_list", ConvertStringToStringList, ConvertStringListToString);
  registerType< std::vector< std::vector< std::string> > >((int)tr::processQt::propertyBrowser::Types::STRING_MATRIX_TYPE, "string_matrix", ConvertStringToStringMatrix, ConvertStringMatrixToString);
  registerType< std::list<te::map::AbstractLayerPtr> >((int)tr::processQt::propertyBrowser::Types::LAYER_LIST_TYPE, "layer_list", ConvertStringToAbstractLayerList, ConvertAbstractLayerListToString);
}

/*  Copyright (C) 2008 National Institute For Space Research (INPE) - Brazil.

This file is part of the TerraLib - a Framework for building GIS enabled applications.

TerraLib is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License,
or (at your option) any later version.

TerraLib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with TerraLib. See COPYING. If not, write to
TerraLib Team at <terralib-team@terralib.org>.
*/

/*!
\file EnumDataType.cpp

\brief

\ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/enum/EnumDataType.h"

// Qt
#include <QtCore>

tr::processQt::propertyBrowser::EnumDataType::EnumDataType() :
  m_dataTypeNone(0),
  m_dataTypeInt(0),
  m_dataTypeDouble(0),
  m_dataTypeLong(0),
  m_dataTypeFloat(0),
  m_dataTypeString(0),
  m_dataTypeBool(0),
  m_dataTypeColor(0),
  m_dataTypeStringList(0),
  m_dataTypeFont(0),
  m_dataTypeEnvelope(0),
  m_dataTypeImage(0),
  m_dataTypeGroup(0),
  m_dataTypeStringVector(0),
  m_dataTypeStringMatrix(0),
  m_dataTypeGeometry(0),
  m_dataTypeItemObserver(0),
  m_dataTypeGroupProperties(0),
  m_dataTypePath(0)
{
  init();
}

tr::processQt::propertyBrowser::EnumDataType::~EnumDataType()
{
  if (m_dataTypeNone)
  {
    delete m_dataTypeNone;
    m_dataTypeNone = 0;
  }
  if (m_dataTypeInt)
  {
    delete m_dataTypeInt;
    m_dataTypeInt = 0;
  }
  if (m_dataTypeDouble)
  {
    delete m_dataTypeDouble;
    m_dataTypeDouble = 0;
  }
  if (m_dataTypeLong)
  {
    delete m_dataTypeLong;
    m_dataTypeLong = 0;
  }
  if (m_dataTypeFloat)
  {
    delete m_dataTypeFloat;
    m_dataTypeFloat = 0;
  }
  if (m_dataTypeString)
  {
    delete m_dataTypeString;
    m_dataTypeString = 0;
  }
  if (m_dataTypeBool)
  {
    delete m_dataTypeBool;
    m_dataTypeBool = 0;
  }

  delete m_dataTypeColor;

  if (m_dataTypeStringList)
  {
    delete m_dataTypeStringList;
    m_dataTypeStringList = 0;
  }
  if (m_dataTypeFont)
  {
    delete m_dataTypeFont;
    m_dataTypeFont = 0;
  }
  if (m_dataTypeEnvelope)
  {
    delete m_dataTypeEnvelope;
    m_dataTypeEnvelope = 0;
  }
  if (m_dataTypeImage)
  {
    delete m_dataTypeImage;
    m_dataTypeImage = 0;
  }
  if (m_dataTypeGroup)
  {
    delete m_dataTypeGroup;
    m_dataTypeGroup = 0;
  }
  if (m_dataTypeStringVector)
  {
    delete m_dataTypeStringVector;
    m_dataTypeStringVector = 0;
  }

  delete m_dataTypeStringMatrix;

  if (m_dataTypeGeometry)
  {
    delete m_dataTypeGeometry;
    m_dataTypeGeometry = 0;
  }
  if (m_dataTypeItemObserver)
  {
    delete m_dataTypeItemObserver;
    m_dataTypeItemObserver = 0;
  }
  if (m_dataTypeGroupProperties)
  {
    delete m_dataTypeGroupProperties;
    m_dataTypeGroupProperties = 0;
  }
  if (m_dataTypePath)
  {
    delete m_dataTypePath;
    m_dataTypePath = 0;
  }
}

void tr::processQt::propertyBrowser::EnumDataType::init()
{
  int id = 1;

  id += Qt::UserRole; // Qt::UserRole: The first role that can be used for application-specific purposes.

  m_dataTypeNone = createEnum(id, "None", this, "None");
  
  ++id;
  m_dataTypeInt = createEnum(id, "Int", this, "Int");

  ++id;
  m_dataTypeDouble = createEnum(id, "Double", this, "Double");

  ++id;
  m_dataTypeLong = createEnum(id, "Long", this, "Long");

  ++id;
  m_dataTypeFloat = createEnum(id, "Float", this, "Float");

  ++id;
  m_dataTypeString = createEnum(id, "String", this, "String");

  ++id;
  m_dataTypeBool = createEnum(id, "Bool", this, "Bool");

  ++id;
  m_dataTypeColor = createEnum(id, "Color", this, "Color");

  ++id;
  m_dataTypeStringList = createEnum(id, "StringList", this, "String List");

  ++id;
  m_dataTypeFont = createEnum(id, "Font", this, "Font");

  ++id;
  m_dataTypeEnvelope = createEnum(id, "Envelope", this, "Envelope");

  ++id;
  m_dataTypeImage = createEnum(id, "Image", this, "Image");

  ++id;
  m_dataTypeGroup = createEnum(id, "Group", this, "Group");
  
  ++id;
  m_dataTypeStringVector = createEnum(id, "StringVector", this, "String Vector");

  ++id;
  m_dataTypeStringMatrix = createEnum(id, "StringMatrix", this, "String Matrix");
  
  ++id;
  m_dataTypeGeometry = createEnum(id, "Geometry", this, "Geometry");

  ++id;
  m_dataTypeItemObserver = createEnum(id, "ItemObserver", this, "Item Observer");

  ++id;
  m_dataTypeGroupProperties = createEnum(id, "GroupProperties", this, "Group Properties");

  ++id;
  m_dataTypePath = createEnum(id, "PathString", this, "Path");
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeNone() const
{
  return m_dataTypeNone;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeInt() const
{
  return m_dataTypeInt;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeDouble() const
{
  return m_dataTypeDouble;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeLong() const
{
  return m_dataTypeLong;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeGroup() const
{
  return m_dataTypeGroup;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeFloat() const
{
  return m_dataTypeFloat;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeString() const
{
  return m_dataTypeString;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeBool() const
{
  return m_dataTypeBool;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeColor() const
{
  return m_dataTypeColor;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeStringList() const
{
  return m_dataTypeStringList;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeFont() const
{
  return m_dataTypeFont;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeEnvelope() const
{
  return m_dataTypeEnvelope;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeImage() const
{
  return m_dataTypeImage;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeStringVector() const
{
  return m_dataTypeStringVector;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeStringMatrix() const
{
  return m_dataTypeStringMatrix;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeGeometry() const
{
  return m_dataTypeGeometry;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeItemObserver() const
{
  return m_dataTypeItemObserver;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypeGroupProperties() const
{
  return m_dataTypeGroupProperties;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::EnumDataType::getDataTypePath() const
{
  return m_dataTypePath;
}

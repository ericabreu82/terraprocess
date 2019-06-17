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
  \file StringLineEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/editor/StringLineEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/Converters.h"

// Qt
#include <QMetaType>

tr::processQt::propertyBrowser::StringLineEditor::StringLineEditor(const QModelIndex& index, QWidget* parent) :
  QLineEdit(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeString())
{
  changeEditorData(index);
}

tr::processQt::propertyBrowser::StringLineEditor::~StringLineEditor()
{

}

QVariant tr::processQt::propertyBrowser::StringLineEditor::getValue()
{
  return this->text();
}

void tr::processQt::propertyBrowser::StringLineEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    std::string newValue = tr::processQt::propertyBrowser::Property::GetValueAs<std::string>(m_property);

    QString qValue = Converters::convert2QString(newValue);
    setText(qValue);
  }
}


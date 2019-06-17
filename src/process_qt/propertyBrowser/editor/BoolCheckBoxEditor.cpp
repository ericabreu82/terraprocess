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
  \file BoolCheckBoxEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/editor/BoolCheckBoxEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

//Qt
#include <QMetaType>

tr::processQt::propertyBrowser::BoolCheckBoxEditor::BoolCheckBoxEditor(const QModelIndex& index, QWidget* parent) :
  QCheckBox(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeBool())
{
  changeEditorData(index);
}

tr::processQt::propertyBrowser::BoolCheckBoxEditor::~BoolCheckBoxEditor()
{

}

QVariant tr::processQt::propertyBrowser::BoolCheckBoxEditor::getValue()
{
  return this->text();
}

void tr::processQt::propertyBrowser::BoolCheckBoxEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    bool newValue = tr::processQt::propertyBrowser::Property::GetValueAs<bool>(m_property);
    setChecked(newValue);

    QString txt = variant.toString();
    setText(txt);
  }
}


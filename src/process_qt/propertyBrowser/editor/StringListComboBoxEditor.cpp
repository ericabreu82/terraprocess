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
  \file StringListComboBoxEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/editor/StringListComboBoxEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/Converters.h"

//Qt
#include <QMetaType>
#include <QStringList>

tr::processQt::propertyBrowser::StringListComboBoxEditor::StringListComboBoxEditor(const QModelIndex& index, QWidget* parent) :
  QComboBox(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeStringList())
{
  changeEditorData(index);
}

tr::processQt::propertyBrowser::StringListComboBoxEditor::~StringListComboBoxEditor()
{

}

QVariant tr::processQt::propertyBrowser::StringListComboBoxEditor::getValue()
{
  return this->currentText();
}

void tr::processQt::propertyBrowser::StringListComboBoxEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    std::string newValue = tr::processQt::propertyBrowser::Property::GetValueAs<std::string>(m_property);

    std::vector<tr::processQt::propertyBrowser::Variant> options = m_property.getOptionChoices();
    addComboOptions(options);
  }
}

void tr::processQt::propertyBrowser::StringListComboBoxEditor::addComboOptions(const std::vector<tr::processQt::propertyBrowser::Variant>& options)
{
  clear();

  QStringList list;
  for (std::vector<Variant>::const_iterator it = options.begin(); it != options.end(); ++it)
  {
    std::string value = (*it).toString();
    QString qValue = tr::processQt::propertyBrowser::Converters::convert2QString(value);
    list.append(qValue);
  }
  addItems(list);

  int index = -1;
  QVariant variant;

  //When the value is not a QString
  QString value = variant.toString();
  variant.setValue(value);

  index = findData(variant, Qt::DisplayRole);
  if (index == -1)
  {
    index = findText(value);
    if (index != -1)
    {
      setCurrentIndex(index);
    }
  }
  else
  {
    setCurrentIndex(index);
  }
}

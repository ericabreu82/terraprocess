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
  \file DoubleSpinBoxEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/editor/DoubleSpinBoxEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

//Qt
#include <QMetaType>

tr::processQt::propertyBrowser::DoubleSpinBoxEditor::DoubleSpinBoxEditor(const QModelIndex& index, QWidget* parent) :
  QDoubleSpinBox(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeDouble())
{
  changeEditorData(index);
  // connect signal / slot
  connect(this, SIGNAL(valueChanged(double)), this, SLOT(onValueChanged(double)));
}

tr::processQt::propertyBrowser::DoubleSpinBoxEditor::~DoubleSpinBoxEditor()
{

}

QVariant tr::processQt::propertyBrowser::DoubleSpinBoxEditor::getValue()
{
  return this->value();
}

void tr::processQt::propertyBrowser::DoubleSpinBoxEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    double newValue = tr::processQt::propertyBrowser::Property::GetValueAs<double>(m_property);
    setValue(newValue);
  }
}

void tr::processQt::propertyBrowser::DoubleSpinBoxEditor::onValueChanged(double d)
{
  double oldValue = tr::processQt::propertyBrowser::Property::GetValueAs<double>(m_property);
  if (oldValue == d)
    return;

  EnumType* type = getType();
  m_property.setValue(d, type);

  emit dataValueChanged(this, m_property);
}

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
  \file AbstractEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/editor/AbstractEditor.h"

tr::processQt::propertyBrowser::AbstractEditor::AbstractEditor(const QModelIndex& index, EnumType* type, ContextPropertyEditor* context) :
  m_dataType(type),
  m_context(context)
{

}

tr::processQt::propertyBrowser::AbstractEditor::~AbstractEditor()
{

}

void tr::processQt::propertyBrowser::AbstractEditor::setEditorData(const QModelIndex& index)
{
  changeEditorData(index);
}

tr::processQt::propertyBrowser::Property tr::processQt::propertyBrowser::AbstractEditor::getProperty()
{
  return m_property;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::AbstractEditor::getType()
{
  return m_dataType;
}

int tr::processQt::propertyBrowser::AbstractEditor::getRole()
{
  int propertyRole = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  return propertyRole;
}

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
  \file EditorFactoryParamsCreate.cpp

  \brief Parameters to create a new editor. 
*/

// TerraLib
#include "src/process_qt/propertyBrowser/factory/editor/EditorFactoryParamsCreate.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

tr::processQt::propertyBrowser::EditorFactoryParamsCreate::EditorFactoryParamsCreate(const QModelIndex& index, const std::vector<Property>& vprops,
  ContextPropertyEditor* context, QWidget* parent) :
  m_index(index),
  m_vprops(vprops),
  m_context(context),
  m_parent(parent)
{

}

tr::processQt::propertyBrowser::EditorFactoryParamsCreate::EditorFactoryParamsCreate(const EditorFactoryParamsCreate& rhs)
{
  this->operator=(rhs);
}

tr::processQt::propertyBrowser::EditorFactoryParamsCreate::~EditorFactoryParamsCreate()
{

}

te::common::AbstractParameters* tr::processQt::propertyBrowser::EditorFactoryParamsCreate::clone() const
{
  return new EditorFactoryParamsCreate(*this);
}

void tr::processQt::propertyBrowser::EditorFactoryParamsCreate::reset() throw(te::common::Exception)
{

}

QModelIndex tr::processQt::propertyBrowser::EditorFactoryParamsCreate::getModelIndex() const
{
  return m_index;
}

QWidget* tr::processQt::propertyBrowser::EditorFactoryParamsCreate::getParent()
{
  return m_parent;
}

std::vector<tr::processQt::propertyBrowser::Property> tr::processQt::propertyBrowser::EditorFactoryParamsCreate::getProperties() const
{
  return m_vprops;
}

tr::processQt::propertyBrowser::ContextPropertyEditor* tr::processQt::propertyBrowser::EditorFactoryParamsCreate::getContextPropertyEditor()
{
  return m_context;
}


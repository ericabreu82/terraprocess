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
  \file EnumType.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/enum/EnumType.h"

//TerraLib
#include <terralib/common/StringUtils.h>

#include <ios> 
#include <iostream>

tr::processQt::propertyBrowser::EnumType::EnumType( int id, const std::string& name, tr::processQt::propertyBrowser::AbstractEnum* parent ) :
  m_id(id),
  m_name(te::common::Convert2UCase(name)),
  m_label(""),
  m_parent(parent),
  m_type(tr::processQt::propertyBrowser::EnumNone)
{
  
}

tr::processQt::propertyBrowser::EnumType::~EnumType()
{

}

int tr::processQt::propertyBrowser::EnumType::getId()
{
  return m_id;
}

std::string tr::processQt::propertyBrowser::EnumType::getName()
{
  return m_name;
}

void tr::processQt::propertyBrowser::EnumType::setName( const std::string& name )
{
  m_name = te::common::Convert2UCase(name);
}

std::string tr::processQt::propertyBrowser::EnumType::getLabel()
{
  return m_label;
}

void tr::processQt::propertyBrowser::EnumType::setLabel( const std::string& label )
{
  m_label = label;
}

tr::processQt::propertyBrowser::AbstractEnum* tr::processQt::propertyBrowser::EnumType::getParent()
{
  return m_parent;
}

tr::processQt::propertyBrowser::EnumTypeFlags tr::processQt::propertyBrowser::EnumType::getType()
{
  return m_type;
}

void tr::processQt::propertyBrowser::EnumType::setType(tr::processQt::propertyBrowser::EnumTypeFlags type )
{
  m_type = type;
}

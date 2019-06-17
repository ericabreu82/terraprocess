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
  \file AbstractEnum.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/enum/AbstractEnum.h"

//TerraLib
#include <terralib/common/StringUtils.h>

tr::processQt::propertyBrowser::AbstractEnum::AbstractEnum()
{

}

tr::processQt::propertyBrowser::AbstractEnum::~AbstractEnum()
{
  
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::AbstractEnum::getEnum( int enumId ) const
{
  EnumType* enumTp = 0;

  for(std::vector<EnumType*>::const_iterator it = m_enums.begin(); it != m_enums.end(); ++it)
  {
    if((*it)->getId() == enumId)
    {
      enumTp = (*it);
      break;
    }
  }

  return enumTp;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::AbstractEnum::getEnum( const std::string& name ) const
{
  //tries to find the enum assuming that the NAME or LABEL was received by parameter
  EnumType* enumTp = 0;

  std::string label = name;
  std::string upperName = te::common::Convert2UCase(name);

  for(std::vector<EnumType*>::const_iterator it = m_enums.begin(); it != m_enums.end(); ++it)
  {
    if ((*it)->getName().compare(upperName) == 0 || (*it)->getLabel().compare(label) == 0)
    {
      enumTp = (*it);
      break;
    }
  }

  return enumTp;
}

int tr::processQt::propertyBrowser::AbstractEnum::maxId()
{
  int max = -1;

  if(m_enums.empty())
    return max;

  for(std::vector<EnumType*>::const_iterator it = m_enums.begin(); it != m_enums.end(); ++it)
  {
    if((*it)->getId() > max)
    {
      max = (*it)->getId();
    }
  }

  return max;
}

int tr::processQt::propertyBrowser::AbstractEnum::minId()
{
  int min = -1;

  if(m_enums.empty())
    return min;

  min = m_enums[0]->getId();

  for(std::vector<EnumType*>::const_iterator it = m_enums.begin(); it != m_enums.end(); ++it)
  {
    if((*it)->getId() < min)
    {
      min = (*it)->getId();
    }
  }

  return min;
}

int tr::processQt::propertyBrowser::AbstractEnum::size()
{
  return (int)m_enums.size();
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::AbstractEnum::createEnum(std::string name, AbstractEnum* type, std::string label)
{
  int id = maxId();
  ++id;

  EnumType* enumType = new EnumType(id, name, type);

  if(label.compare("") == 0)
  {
    label = name;
  }
  enumType->setLabel(label);

  m_enums.push_back(enumType);

  return enumType;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::AbstractEnum::createEnum(int id, const std::string& name, AbstractEnum* type, const std::string& label)
{
  EnumType* enumType = 0; 
  if (getEnum(id) != 0) // checks already registered an enum with id
  {
    return enumType;
  }

  enumType = new EnumType(id, name, type);

  std::string newLabel = label;
  if (label.compare("") == 0)
  {
    newLabel = name;
  }
  enumType->setLabel(newLabel);

  m_enums.push_back(enumType);

  return enumType;
}


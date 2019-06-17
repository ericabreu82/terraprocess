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
  \file Enums.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/enum/Enums.h"

tr::processQt::propertyBrowser::Enums::Enums() :
  m_dataType(new EnumDataType())
{

}

tr::processQt::propertyBrowser::Enums::~Enums()
{
  delete m_dataType;
}

void tr::processQt::propertyBrowser::Enums::setEnumDataType( EnumDataType* type )
{
  if (m_dataType)
  {
    delete type;
    type = 0;
  }
  m_dataType = type;
}

tr::processQt::propertyBrowser::EnumDataType* tr::processQt::propertyBrowser::Enums::getEnumDataType()
{
  return m_dataType;
}


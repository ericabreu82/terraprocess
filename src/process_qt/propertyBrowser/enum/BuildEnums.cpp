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
  \file BuildEnums.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/enum/BuildEnums.h"
#include "src/process_qt/propertyBrowser/enum/EnumDataType.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

tr::processQt::propertyBrowser::BuildEnums::BuildEnums() :
  m_dataType(0),
  m_objType(0),
  m_gridStyleType(0),
  m_lineStyleType(0),
  m_modeType(0),
  m_templateType(0)
{

}

tr::processQt::propertyBrowser::BuildEnums::~BuildEnums()
{
  if(m_dataType)
  {
    delete m_dataType;
    m_dataType = 0;
  }

  if(m_objType)
  {
    delete m_objType;
    m_objType = 0;
  }

  if(m_gridStyleType)
  {
    delete m_gridStyleType;
    m_gridStyleType = 0;
  }

  if(m_lineStyleType)
  {
    delete m_lineStyleType;
    m_lineStyleType = 0;
  }

  if(m_modeType)
  {
    delete m_modeType;
    m_modeType = 0;
  }

  if(m_templateType)
  {
    delete m_templateType;
    m_templateType = 0;
  }
}

void tr::processQt::propertyBrowser::BuildEnums::build()
{
  if(!Enums::getInstance().getEnumDataType())
  {
    m_dataType = new EnumDataType;
    Enums::getInstance().setEnumDataType(m_dataType);
  }
}

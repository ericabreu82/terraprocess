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
  \file AbstractRender.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/render/AbstractRender.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/Converters.h"

// Qt
#include <QVariant>

tr::processQt::propertyBrowser::AbstractRender::AbstractRender()
{

}

tr::processQt::propertyBrowser::AbstractRender::~AbstractRender()
{

}

QString tr::processQt::propertyBrowser::AbstractRender::propertyToQString(QVariant& value)
{
  tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(value);
  const te::dt::AbstractData* absData = prop.getValue();

  QString qValue;
  if (absData)
  {
    std::string svalue = absData->toString();
    qValue = QString(tr::processQt::propertyBrowser::Converters::convert2QString(svalue));
  }
  return qValue;
}

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
  \file BuildRender.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "BuildRender.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/factory/render/RenderFactory.h"
#include "src/process_qt/propertyBrowser/factory/render/RenderFactoryParamsCreate.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// STL
#include <string>

// Qt
#include <QMetaType>
#include <QModelIndex>
#include <QVariant>

tr::processQt::propertyBrowser::BuildRender::BuildRender()
{
  
}

tr::processQt::propertyBrowser::BuildRender::~BuildRender()
{
 
}

tr::processQt::propertyBrowser::AbstractRender* tr::processQt::propertyBrowser::BuildRender::buildRender(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index)
{
  RenderFactoryParamsCreate params;

  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);

  tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);

  te::common::ParameterizedAbstractFactory<AbstractRender, std::string, RenderFactoryParamsCreate>::dictionary_type& d = te::common::ParameterizedAbstractFactory<AbstractRender, std::string, RenderFactoryParamsCreate>::getDictionary();

  std::string renderName = prop.getType()->getName();
  RenderFactory* fact = dynamic_cast<RenderFactory*>(d.find(renderName));
  
  AbstractRender* render = 0;
  if (fact)
  {
    render = tr::processQt::propertyBrowser::RenderFactory::make(renderName, params);
  }
  return render;
}


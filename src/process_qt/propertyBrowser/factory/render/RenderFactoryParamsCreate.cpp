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
  \file RenderFactoryParamsCreate.cpp

  \brief Parameters to create a new render. 
*/

#include "src/process_qt/propertyBrowser/factory/render/RenderFactoryParamsCreate.h"

tr::processQt::propertyBrowser::RenderFactoryParamsCreate::RenderFactoryParamsCreate()
{

}

tr::processQt::propertyBrowser::RenderFactoryParamsCreate::RenderFactoryParamsCreate(const RenderFactoryParamsCreate& rhs)
{
  this->operator=(rhs);
}

tr::processQt::propertyBrowser::RenderFactoryParamsCreate::~RenderFactoryParamsCreate()
{

}

te::common::AbstractParameters* tr::processQt::propertyBrowser::RenderFactoryParamsCreate::clone() const
{
  return new RenderFactoryParamsCreate(*this);
}

void tr::processQt::propertyBrowser::RenderFactoryParamsCreate::reset() throw(te::common::Exception)
{

}


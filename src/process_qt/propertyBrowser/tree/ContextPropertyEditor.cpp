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
  \file ContextPropertyEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/tree/ContextPropertyEditor.h"
#include "src/process_qt/propertyBrowser/property/Properties.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

// Qt
#include <QStringList>
#include <QGraphicsItem>

tr::processQt::propertyBrowser::ContextPropertyEditor::ContextPropertyEditor(AbstractProxy* proxy, tr::processQt::graphics::Scene* scene):
  m_proxy(proxy),
  m_scene(scene)
{

}

tr::processQt::propertyBrowser::ContextPropertyEditor::~ContextPropertyEditor()
{

}

tr::processQt::propertyBrowser::AbstractProxy* tr::processQt::propertyBrowser::ContextPropertyEditor::getProxy()
{
  return m_proxy;
}

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
  \file BuildTreeItem.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/tree/BuildTreeItem.h"
#include "src/process_qt/propertyBrowser/tree/PropertyTreeItem.h"
#include "src/process_qt/propertyBrowser/factory/treeItem/PropertyTreeItemFactory.h"
#include "src/process_qt/propertyBrowser/factory/treeItem/PropertyTreeItemFactoryParamsCreate.h"

#include <terralib/common/ParameterizedAbstractFactory.h>

// STL
#include <string>

tr::processQt::propertyBrowser::BuildTreeItem::BuildTreeItem()
{
  
}

tr::processQt::propertyBrowser::BuildTreeItem::~BuildTreeItem()
{
 
}

tr::processQt::propertyBrowser::PropertyTreeItem* tr::processQt::propertyBrowser::BuildTreeItem::buildTreeItem(Property & prop, QTreeWidgetItem* parent)
{
  PropertyTreeItemFactoryParamsCreate params(prop, parent);

  EnumType* type = prop.getType();
  std::string editorName = type->getName();    

  te::common::ParameterizedAbstractFactory<PropertyTreeItem, std::string, PropertyTreeItemFactoryParamsCreate>::dictionary_type& d = te::common::ParameterizedAbstractFactory<PropertyTreeItem, std::string, PropertyTreeItemFactoryParamsCreate>::getDictionary();

  PropertyTreeItemFactory* fact = dynamic_cast<PropertyTreeItemFactory*>(d.find(editorName));
  PropertyTreeItem* treeItem = 0;
  if (fact)
  {
    treeItem = tr::processQt::propertyBrowser::PropertyTreeItemFactory::make(editorName, params);
  }
  else
  {
    treeItem = new PropertyTreeItem(prop, parent);
  }
  return treeItem;
}


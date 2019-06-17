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
  \file PropertyTree.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/tree/PropertyTreeItem.h"
#include "src/process_qt/propertyBrowser/tree/PropertyTree.h"

// Qt
#include <QMetaType>
#include <QString>
#include <QVariant>
#include <QTreeWidget>

tr::processQt::propertyBrowser::PropertyTreeItem::PropertyTreeItem(Property & prop, QTreeWidgetItem* parent) :
  QTreeWidgetItem(parent),
  m_property(prop)
{
  setFlags(flags() | Qt::ItemIsEditable);
}

tr::processQt::propertyBrowser::PropertyTreeItem::~PropertyTreeItem()
{

}

void tr::processQt::propertyBrowser::PropertyTreeItem::setData(int column, int role, const QVariant & value)
{
  QTreeWidgetItem::setData(column, role, value);

  if (column != 0)
  {
    QVariant name = data(0, Qt::UserRole); // get name of the property

    // update property
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(value);

    if (parent())
    {
      PropertyTreeItem* parentTreeItem = dynamic_cast<PropertyTreeItem*>(parent());
      if (parentTreeItem)
      {
        //QTreeWidgetItem::setData(column, role, value);
        parentTreeItem->refresh(column, role, name.toString(), value, this); // refresh parent
      }
    }
    else
    {
      /* For each setData there is an internal call to the model->emitDataChanged, so with each change,
      the QTreeWidget's itemChanged method is called. In case of this customization,
      when the item has a parent, then only the parent could notify */
      // this item data has changed, so notify QTreeWidget
      QTreeWidget* tree = treeWidget();
      if (tree)
      {
        PropertyTree* propTree = dynamic_cast<PropertyTree*>(tree);
        if (propTree)
        {
          propTree->propertyTreeItemChanged(this, column);
        }
      }
    }
  }
}

tr::processQt::propertyBrowser::Property tr::processQt::propertyBrowser::PropertyTreeItem::getProperty()
{
  return m_property;
}

void tr::processQt::propertyBrowser::PropertyTreeItem::setPropertyValue(QVariant variant)
{
  // do nothing
}

void tr::processQt::propertyBrowser::PropertyTreeItem::refresh(int column, int role, QString name, QVariant value, QTreeWidgetItem* childItem)
{
  // do nothing
}

void tr::processQt::propertyBrowser::PropertyTreeItem::refreshChild(int column, int role, QString name, QVariant value)
{
  int count = childCount();
  for (int i = 0; i < count; ++i)
  {
    QTreeWidgetItem* itemChild = child(i);
    if (itemChild->data(0, Qt::UserRole) == name)
    {
      setChildData(itemChild, column, role, value);
      break;
    }
  }
}

void tr::processQt::propertyBrowser::PropertyTreeItem::setChildData(QTreeWidgetItem* childItem, int column, int role, QVariant value)
{
  childItem->setData(column, role, value); // Property Value
  PropertyTreeItem* childTreeItem = dynamic_cast<PropertyTreeItem*>(childItem);
  if (childTreeItem)
  {
    Property prop = childTreeItem->getProperty(); //How update child property(toSomething()) ?
  }
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::PropertyTreeItem::getDataType()
{
  return m_property.getType();
}

int tr::processQt::propertyBrowser::PropertyTreeItem::getDataRole()
{
  int propertyRole = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  return propertyRole;
}


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
  \file BoolCheckBoxEditorFactory.cpp

  \brief This is the concrete factory for tree items.
*/

// TerraLib
#include "src/process_qt/propertyBrowser/factory/treeItem/EnvelopePropertyTreeItemFactory.h"
#include "src/process_qt/propertyBrowser/factory/treeItem/PropertyTreeItemFactoryParamsCreate.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/tree/EnvelopePropertyTreeItem.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/tree/PropertyTreeItem.h"

// Qt
#include <QMetaType>
#include <QVariant>

tr::processQt::propertyBrowser::PropertyTreeItem* tr::processQt::propertyBrowser::EnvelopePropertyTreeItemFactory::build(PropertyTreeItemFactoryParamsCreate params)
{
  Property prop = params.getProperty();
  QTreeWidgetItem* parent = params.getParent();

  return createEnvelopeDataTreeItem(prop, parent);
}

tr::processQt::propertyBrowser::EnvelopePropertyTreeItemFactory::EnvelopePropertyTreeItemFactory() :
  PropertyTreeItemFactory(Enums::getInstance().getEnumDataType()->getDataTypeEnvelope()->getName())
{

}

tr::processQt::propertyBrowser::EnvelopePropertyTreeItemFactory::~EnvelopePropertyTreeItemFactory()
{

}

tr::processQt::propertyBrowser::PropertyTreeItem* tr::processQt::propertyBrowser::EnvelopePropertyTreeItemFactory::createEnvelopeDataTreeItem(Property & prop, QTreeWidgetItem* parent)
{
  EnvelopePropertyTreeItem* envelopePropertyTreeItem = new EnvelopePropertyTreeItem(prop, parent);

  te::gm::Envelope env = tr::processQt::propertyBrowser::Property::GetValueAs<te::gm::Envelope>(prop);
  if (!env.isValid())
  {
    env = te::gm::Envelope(0, 0, 0, 0);
  }

  QString firstChildName("x1");
  double  childValue = env.getLowerLeftX();
  tr::processQt::propertyBrowser::PropertyTreeItem* x1 = createDataTreeItemChild(firstChildName, childValue, envelopePropertyTreeItem);

  QString secondChildName("y1");
  childValue = env.getLowerLeftY();
  createDataTreeItemChild(secondChildName, childValue, envelopePropertyTreeItem);

  QString thirdChildName("x2");
  childValue = env.getUpperRightX();
  createDataTreeItemChild(thirdChildName, childValue, envelopePropertyTreeItem);

  QString fourthChildName("y2");
  childValue = env.getUpperRightY();
  createDataTreeItemChild(fourthChildName, childValue, envelopePropertyTreeItem);
  
  return envelopePropertyTreeItem;
}

tr::processQt::propertyBrowser::PropertyTreeItem* tr::processQt::propertyBrowser::EnvelopePropertyTreeItemFactory::createDataTreeItemChild(QString name, double value, QTreeWidgetItem* parent)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  EnumType* type = Enums::getInstance().getEnumDataType()->getDataTypeDouble();

  Property prop;
  prop.setName(name.toStdString());

  double dValue = value;
  prop.setValue(dValue, type);

  PropertyTreeItem* newItem = new PropertyTreeItem(prop, parent); //Detail to generate a hierarchical tree, the parent must be passed in the constructor QTreeWidgetItem
  newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
  newItem->setText(0, name); // Property Name
  newItem->setData(0, Qt::UserRole, QVariant(name)); // Property Name

  // Second Column
  QVariant variant = QVariant::fromValue<tr::processQt::propertyBrowser::Property>(prop);
  newItem->setData(1, propertyType, variant); // Property Value

  return newItem;
}


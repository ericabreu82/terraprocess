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
  \file EnvelopePropertyTreeItem.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/tree/EnvelopePropertyTreeItem.h"

// Qt
#include <QString>
#include <QVariant>

tr::processQt::propertyBrowser::EnvelopePropertyTreeItem::EnvelopePropertyTreeItem(Property & prop, QTreeWidgetItem* parent) :
  PropertyTreeItem(prop, parent),
  m_x1Name("x1"),
  m_y1Name("y1"),
  m_x2Name("x2"),
  m_y2Name("y2")
{
  setFlags(flags() & (~Qt::ItemIsEditable)); // remove editable flag
}

tr::processQt::propertyBrowser::EnvelopePropertyTreeItem::~EnvelopePropertyTreeItem()
{

}

void tr::processQt::propertyBrowser::EnvelopePropertyTreeItem::refresh(int column, int role, QString name, QVariant value, QTreeWidgetItem* childItem)
{
  if (column == 0)
    return;

  // get childItem value
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(value);
  double doubleValue = tr::processQt::propertyBrowser::Property::GetValueAs<double>(prop);

  int dataRole = getDataRole();

  QVariant currentDataValue = data(1, dataRole).toRectF();
  int count = childCount();

  te::gm::Envelope env = tr::processQt::propertyBrowser::Property::GetValueAs<te::gm::Envelope>(m_property);
  double x = env.getLowerLeftX();
  double y = env.getLowerLeftY();
  double width = env.getWidth();
  double height = env.getHeight();

  for (int i = 0; i < count; ++i)
  {
    QTreeWidgetItem* itemChild = child(i);

    if (itemChild == childItem)
    {
      if (itemChild->data(0, Qt::UserRole) == name)
      {
        if (name == m_x1Name)
          env = te::gm::Envelope(doubleValue, y, x + width, y + height);
        if (name == m_y1Name)
          env = te::gm::Envelope(x, doubleValue, x + width, y + height);
        if (name == m_x2Name)
          env = te::gm::Envelope(x, y, doubleValue, y + height);
        if (name == m_y2Name)
          env = te::gm::Envelope(x, y, x + width, doubleValue);

        m_property.setValue(env, m_property.getType());

        // Property to QVariant (Wrapper)
        QVariant variant = QVariant::fromValue<tr::processQt::propertyBrowser::Property>(m_property);
        setData(1, dataRole, variant);
        break;
      }
    }
  }
}


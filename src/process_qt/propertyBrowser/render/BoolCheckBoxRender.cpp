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
  \file BoolCheckBoxRender.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/render/BoolCheckBoxRender.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// Qt
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QMetaType>

tr::processQt::propertyBrowser::BoolCheckBoxRender::BoolCheckBoxRender()
{
  
}

tr::processQt::propertyBrowser::BoolCheckBoxRender::~BoolCheckBoxRender()
{

}

void tr::processQt::propertyBrowser::BoolCheckBoxRender::render(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);

  if (variant.isValid())
  {
    QString value = propertyToQString(variant);
    painter->drawText(option.rect, Qt::AlignLeft, value);
  }
}


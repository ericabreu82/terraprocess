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
  \file EnvelopeRender.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/render/EnvelopeRender.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// Qt
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QString>

tr::processQt::propertyBrowser::EnvelopeRender::EnvelopeRender()
{

}

tr::processQt::propertyBrowser::EnvelopeRender::~EnvelopeRender()
{

}

void tr::processQt::propertyBrowser::EnvelopeRender::render(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);

  if (variant.isValid())
  {
    tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    te::gm::Envelope env = tr::processQt::propertyBrowser::Property::GetValueAs<te::gm::Envelope>(prop);

    QString value = QString("[(%1, %2), %3 x %4]").arg(QString::number(env.getLowerLeftX()))\
      .arg(QString::number(env.getLowerLeftY()))
      .arg(QString::number(env.getUpperRightX()))
      .arg(QString::number(env.getUpperRightY()));

    painter->drawText(option.rect, Qt::AlignLeft, value);
  }
}


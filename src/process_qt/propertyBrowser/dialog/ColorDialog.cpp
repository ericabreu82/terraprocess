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
  \file ColorDialog.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/dialog/ColorDialog.h"
#include "src/process_qt/propertyBrowser/dialog/ColorWidget.h"
#include "src/process_qt/propertyBrowser/enum/EnumDataType.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

// TerraLib
#include <terralib/color/RGBAColor.h>

// Qt
#include <QColor>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QVBoxLayout>


tr::processQt::propertyBrowser::ColorDialog::ColorDialog(QWidget* parent) :
  QDialog(parent),
  m_okClicked(false)
{
  this->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

  m_colorWidget = new ColorWidget(this);
  
  QPushButton* qHelpButton = new QPushButton("Help");
  QPushButton* qOkButton = new QPushButton("OK");
  QPushButton* qCloseButton = new QPushButton("Close");

  QHBoxLayout* horizontalLayout = new QHBoxLayout();
  horizontalLayout->addWidget(qHelpButton);
  horizontalLayout->addStretch();
  horizontalLayout->addWidget(qOkButton);
  horizontalLayout->addWidget(qCloseButton);

  QVBoxLayout* layoutMain = new QVBoxLayout(this);
  layoutMain->addWidget(m_colorWidget);
  layoutMain->addStretch();
  layoutMain->addLayout(horizontalLayout);
  layoutMain->setSizeConstraint(QLayout::SetFixedSize);

  connect(qOkButton, SIGNAL(clicked()), this, SLOT(on_okPushButton_clicked()));
  connect(qCloseButton, SIGNAL(clicked()), this, SLOT(on_closePushButton_clicked()));
}

tr::processQt::propertyBrowser::ColorDialog::~ColorDialog()
{
  delete m_colorWidget;
}

void tr::processQt::propertyBrowser::ColorDialog::init()
{
  
}

void tr::processQt::propertyBrowser::ColorDialog::setCurrentColor(const QColor& color)
{
  m_colorWidget->setColor(color);
}

QColor tr::processQt::propertyBrowser::ColorDialog::getCurrentColor() const
{
  return m_colorWidget->getColor();
}

QColor tr::processQt::propertyBrowser::ColorDialog::getColor(const QColor& initial, QWidget* parent, const QString& title)
{
  ColorDialog colorDialog(parent);
  colorDialog.setCurrentColor(initial);
  if (title.isEmpty() == false)
  {
    colorDialog.setWindowTitle(title);
  }

  if (colorDialog.exec() == QDialog::Accepted)
  {
    return colorDialog.getCurrentColor();
  }

  return initial;
}

void tr::processQt::propertyBrowser::ColorDialog::accept()
{
  m_okClicked = true;

  close();
}

void tr::processQt::propertyBrowser::ColorDialog::on_okPushButton_clicked()
{
  accept();
}

void tr::processQt::propertyBrowser::ColorDialog::on_closePushButton_clicked()
{
  close();
}

bool tr::processQt::propertyBrowser::ColorDialog::event( QEvent * e )
{
  return QDialog::event(e);
}

void tr::processQt::propertyBrowser::ColorDialog::closeEvent( QCloseEvent * event )
{
  if(m_okClicked)
  {
    m_okClicked = false;
    event->accept();
  }
  else
  {
    QDialog::closeEvent(event);
  }
}

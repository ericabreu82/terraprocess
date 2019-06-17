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
  \file ColorEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/editor/ColorPickerEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/dialog/ColorDialog.h"

//Qt
#include <QMetaType>
#include <QString>
#include <QVariant>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QEvent>
#include <QKeyEvent>
#include <QStyleOption>
#include <QPainter>
#include <QStyle>
#include <QApplication>
#include <QFontDialog>

tr::processQt::propertyBrowser::ColorPickerEditor::ColorPickerEditor(const QModelIndex& index, ContextPropertyEditor* context, QWidget* parent) :
  QWidget(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeColor(), context),
  m_textLabel(0),
  m_button(0)
{
  createGroupBox();
  changeEditorData(index);
}

tr::processQt::propertyBrowser::ColorPickerEditor::~ColorPickerEditor()
{

}

QVariant tr::processQt::propertyBrowser::ColorPickerEditor::getValue()
{
  return m_textLabel->text();
}

void tr::processQt::propertyBrowser::ColorPickerEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    const te::color::RGBAColor& newValue = tr::processQt::propertyBrowser::Property::GetValueAs<te::color::RGBAColor>(m_property);

    m_color = QColor(newValue.getRed(), newValue.getGreen(), newValue.getBlue(), newValue.getAlpha());
    if (m_textLabel)
    {
      QPalette ptt(m_textLabel->palette());
      if (m_color.isValid())
      {
        ptt.setColor(m_textLabel->backgroundRole(), m_color);
        m_textLabel->setAutoFillBackground(true);
        m_textLabel->setPalette(ptt);
      }      
    }
  }
}

void tr::processQt::propertyBrowser::ColorPickerEditor::createGroupBox()
{
  QHBoxLayout* hlayout = new QHBoxLayout(this);

  setupTreeViewEditorMargin(hlayout);
  m_textLabel = new QLabel("");

  m_textLabel->setFixedWidth(20);

  m_button = new QToolButton(this);
  m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
  m_button->setFixedWidth(20);
  m_button->setText("...");
  m_button->installEventFilter(this);

  connect(m_button, SIGNAL(clicked(bool)), this, SLOT(onButtonClicked(bool)));
  
  setFocusProxy(m_button);
  setFocusPolicy(m_button->focusPolicy());

  hlayout->setSpacing(0);
  hlayout->addWidget(m_textLabel);

  QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored);
  hlayout->addItem(spacer);

  hlayout->addWidget(m_button);

  setLayout(hlayout);
}

bool tr::processQt::propertyBrowser::ColorPickerEditor::eventFilter(QObject * watched, QEvent * event)
{
  if (watched == m_button)
  {
    if (event->type() == QEvent::KeyRelease)
    {
      QKeyEvent* kEvent = dynamic_cast<QKeyEvent*>(event);
      if (kEvent)
      {
        if (kEvent->key() == Qt::Key_Return)
        {
          event->ignore();
          return true;
        }
      }
    }
  }
  return QWidget::eventFilter(watched, event);
}

void tr::processQt::propertyBrowser::ColorPickerEditor::paintEvent(QPaintEvent * event)
{
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void tr::processQt::propertyBrowser::ColorPickerEditor::onButtonClicked(bool checked)
{
  emit showDlg();
  getColor();
}

void tr::processQt::propertyBrowser::ColorPickerEditor::getColor()
{
  QColor color = configColor(m_textLabel);
  
  if (color.isValid())
  {
    te::color::RGBAColor rgba(color.red(), color.green(), color.blue(), color.alpha());
    m_property.setValue(rgba, m_property.getType());
    m_color = color;

    //Emit our own signal.
    emit dataValueChanged(this, m_property);
  }
}

void tr::processQt::propertyBrowser::ColorPickerEditor::setupTreeViewEditorMargin(QLayout* layout)
{
  int decorationMargin = 4;

  if(QApplication::layoutDirection() == Qt::LeftToRight)
  {
    layout->setContentsMargins(decorationMargin, 0, 0, 0);
  }
  else
  {
    layout->setContentsMargins(0, 0, decorationMargin, 0);
  }
}

QColor tr::processQt::propertyBrowser::ColorPickerEditor::configColor(QWidget* widget)
{
  QPalette ptt(widget->palette());
  QBrush brush = ptt.brush(widget->backgroundRole());
  
  QColor color = ColorDialog::getColor(brush.color(), this, tr("Select Color"));
  if (color.isValid())
  {
    ptt.setColor(widget->backgroundRole(), m_color);
    widget->setAutoFillBackground(true);
    widget->setPalette(ptt);
  }  
  return color;
}

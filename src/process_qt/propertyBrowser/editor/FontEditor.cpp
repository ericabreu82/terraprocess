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
  \file FontEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "FontEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/Converters.h"

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
#include <QColor>

tr::processQt::propertyBrowser::FontEditor::FontEditor(const QModelIndex& index, ContextPropertyEditor* context, QWidget* parent) :
  QWidget(parent),
  AbstractEditor(index, Enums::getInstance().getEnumDataType()->getDataTypeFont(), context),
  m_textLabel(0),
  m_button(0)
{
  createGroupBox();
  changeEditorData(index);
}

tr::processQt::propertyBrowser::FontEditor::~FontEditor()
{

}

QVariant tr::processQt::propertyBrowser::FontEditor::getValue()
{
  return m_textLabel->text();
}

void tr::processQt::propertyBrowser::FontEditor::changeEditorData(const QModelIndex& index)
{
  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  if (variant.isValid() && !variant.isNull())
  {
    m_property = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    tr::processQt::propertyBrowser::Font newValue = tr::processQt::propertyBrowser::Property::GetValueAs<tr::processQt::propertyBrowser::Font>(m_property);
    
    m_font = Converters::convertToQfont(newValue);
    if (m_textLabel)
    {
      m_textLabel->setText(m_font.family());
    }
  }
}

void tr::processQt::propertyBrowser::FontEditor::createGroupBox()
{
  QHBoxLayout* hlayout = new QHBoxLayout(this);

  setupTreeViewEditorMargin(hlayout);
  m_textLabel = new QLabel("");

  QColor color(255, 255, 255);
  m_textLabel->setPalette(QPalette(color));

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

bool tr::processQt::propertyBrowser::FontEditor::eventFilter(QObject * watched, QEvent * event)
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

void tr::processQt::propertyBrowser::FontEditor::paintEvent(QPaintEvent * event)
{
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void tr::processQt::propertyBrowser::FontEditor::onButtonClicked(bool checked)
{
  emit showDlg();
  getFont();
}

void tr::processQt::propertyBrowser::FontEditor::getFont()
{
  bool ok;
  QFont font = QFontDialog::getFont(&ok, m_font, this);
  if (ok)
  {
    // font is set to the font the user selected  
    m_font = font;
  }
  else 
  {
    // the user canceled the dialog; font is set to the initial
    return;
  }
  
  tr::processQt::propertyBrowser::Font newFont;
  newFont.setPointSize(m_font.pointSize());
  newFont.setFamily(Converters::convert2StdString(m_font.family()));
  newFont.setBold(m_font.bold());
  newFont.setItalic(m_font.italic());
  newFont.setKerning(m_font.kerning());
  newFont.setStrikeout(m_font.strikeOut());
  newFont.setUnderline(m_font.underline());

  m_property.setValue(newFont, m_property.getType());
  
  //Emit our own signal.
  emit dataValueChanged(this, m_property);
}

void tr::processQt::propertyBrowser::FontEditor::setupTreeViewEditorMargin(QLayout* layout)
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


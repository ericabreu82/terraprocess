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
  \file PropertyDelegate.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/tree/PropertyDelegate.h"
#include "src/process_qt/propertyBrowser/editor/AbstractEditor.h"
#include "src/process_qt/propertyBrowser/editor/BuildEditor.h"
#include "src/process_qt/propertyBrowser/render/BuildRender.h"
#include "src/process_qt/propertyBrowser/render/AbstractRender.h"
#include "src/process_qt/propertyBrowser/factory/editor/EditorFactoryParamsCreate.h"
#include "src/process_qt/propertyBrowser/tree/ContextPropertyEditor.h"

// Qt
#include <QApplication>
#include <QPainter>

tr::processQt::propertyBrowser::PropertyDelegate::PropertyDelegate(ContextPropertyEditor* context, BuildRender* build, QObject* parent) :
  QStyledItemDelegate(parent),
  m_currentEditor(0),
  m_currentEditorRow(-1),
  m_currentEditorColumn(-1),
  m_buildRender(build),
  m_context(context)
{
  if (!build)
  {
    m_buildRender = new BuildRender;
  }
}

tr::processQt::propertyBrowser::PropertyDelegate::~PropertyDelegate()
{
  if (m_buildRender)
  {
    delete m_buildRender;
    m_buildRender = 0;
  }

  if (m_context)
  {
    delete m_context;
    m_context = 0;
  }
}

void tr::processQt::propertyBrowser::PropertyDelegate::setProperties(const std::vector<Property>& vprops)
{
  m_vprops = vprops;
}

QWidget * tr::processQt::propertyBrowser::PropertyDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
  if (index.column() == 0)
  {
    m_currentEditor =  QStyledItemDelegate::createEditor(parent, option, index);
  }
  else
  {
    m_currentEditor = createFromFactory(parent, option, index);
    if (m_currentEditor != 0)
    {
      m_currentEditorRow = index.row();
      m_currentEditorColumn = index.column();
    }
  }
  return m_currentEditor;
}

void tr::processQt::propertyBrowser::PropertyDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
  AbstractEditor* abstractEditor = dynamic_cast<AbstractEditor*>(editor);
  if (abstractEditor)
  {
    abstractEditor->setEditorData(index);
  }
}

void tr::processQt::propertyBrowser::PropertyDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const
{
  AbstractEditor* abstractEditor = dynamic_cast<AbstractEditor*>(editor);
  if (abstractEditor)
  {
    if (index.column() == 1)
    {
      tr::processQt::propertyBrowser::Property currentProperty = abstractEditor->getProperty();
      int role = abstractEditor->getRole(); // important because this delegate is using custom data type(role) and not exist in Qt default implementation
      const te::dt::AbstractData* currentAbsData = currentProperty.getValue();

      QVariant modelData = model->data(index, role);
      tr::processQt::propertyBrowser::Property modelProp = qvariant_cast<tr::processQt::propertyBrowser::Property>(modelData);
      const te::dt::AbstractData* modelAbsData = modelProp.getValue();

      if (currentAbsData == modelAbsData)
        return;
      // Property to QVariant (Wrapper)
      QVariant value = QVariant::fromValue<tr::processQt::propertyBrowser::Property>(currentProperty);
      model->setData(index, value, role);
    }
  }
}

void tr::processQt::propertyBrowser::PropertyDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
  editor->setGeometry(option.rect);
}

void tr::processQt::propertyBrowser::PropertyDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
  if (index.column() == 1)
  {
    int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
    QVariant variant = index.data(propertyType);

    tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
    std::string propName = prop.getName();

    std::string renderName = prop.getType()->getName();
    if (renderName.compare("NONE") != 0)
    {
      AbstractRender* render = m_buildRender->buildRender(painter, option, index);
      if (render)
      {
        render->render(painter, option, index);
        delete render;
      }
    }
    return;
  }
  QStyledItemDelegate::paint(painter, option, index);
}

QWidget* tr::processQt::propertyBrowser::PropertyDelegate::createFromFactory(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
  QWidget* editor = 0;

  EditorFactoryParamsCreate params(index, m_vprops, m_context, parent);

  BuildEditor build;
  AbstractEditor* abstractEditor = build.buildEditor(params);  
  if (abstractEditor)
  {
    editor = dynamic_cast<QWidget*>(abstractEditor);
    if (editor)
    {
      // connect signal / slot
      connect(editor, SIGNAL(dataValueChanged(QWidget*, Property)), this, SLOT(onDataValueChanged(QWidget*, Property)));
    }
  }
  return editor;
}

void tr::processQt::propertyBrowser::PropertyDelegate::onDataValueChanged(QWidget* widget, const Property& prop)
{
  if (widget == m_currentEditor)
  {
    // Signal from QItemDelegate
    commitData(widget); // call setEditorData()
  }
}


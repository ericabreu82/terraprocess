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
  \file PropertyDelegate.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_DELEGATE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_DELEGATE__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// STL
#include <vector>

// Qt
#include <QStyledItemDelegate>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class BuildRender;
      class ContextPropertyEditor;

      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT PropertyDelegate : public QStyledItemDelegate
      {
        Q_OBJECT //for slots/signals

      public:

        PropertyDelegate(ContextPropertyEditor* context, BuildRender* build = 0, QObject * parent = 0);

        virtual ~PropertyDelegate();

        virtual void setProperties(const std::vector<Property>& vprops);

        virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

        virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;

        virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

        virtual void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;

        virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

      signals:

        void dataEditorChanged(const Property& prop, int row, int column);

      protected slots:

        void onDataValueChanged(QWidget* widget, const Property& prop);

      protected:

        virtual QWidget* createFromFactory(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

      protected:

        std::vector<Property>           m_vprops;
        mutable QWidget* m_currentEditor;
        mutable int                     m_currentEditorRow;
        mutable int                     m_currentEditorColumn;
        BuildRender* m_buildRender;
        ContextPropertyEditor* m_context;
      };
    }
  }
}

#endif



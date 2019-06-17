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
  \file ColorPickerEditor.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_PICKER_EDITOR__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_PICKER_EDITOR__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/editor/AbstractEditor.h"

// STL
#include <vector>

// Qt
#include <QWidget>
#include <QColor>

class QLabel;
class QToolButton;
class QEvent;
class QLayout;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class ContextPropertyEditor;

      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT ColorPickerEditor : public QWidget, public AbstractEditor
      {
        Q_OBJECT //for slots/signals

      public:

        ColorPickerEditor(const QModelIndex& index, ContextPropertyEditor* context, QWidget* parent = 0);

        virtual ~ColorPickerEditor();

        virtual QVariant getValue();

        virtual bool	eventFilter(QObject* watched, QEvent* event);

      signals:

        void dataValueChanged(QWidget* widget, const Property& prop);

        void showDlg();

      protected slots:

        void onButtonClicked(bool checked = false);

      protected:

        virtual void changeEditorData(const QModelIndex& index);

        void createGroupBox();

        virtual void paintEvent(QPaintEvent* event);

        virtual void getColor();

        void setupTreeViewEditorMargin(QLayout* layout);

        virtual QColor configColor(QWidget* widget);

      protected:

        QColor          m_color;
        QLabel* m_textLabel;
        QToolButton* m_button;
      };
    }
  }
}

#endif



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
  \file DoubleSpinBoxEditor.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DOUBLE_SPINBOX_EDITOR_H 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DOUBLE_SPINBOX_EDITOR_H

#include "src/process_qt/Config.h"
#include "../property/Property.h"
#include "AbstractEditor.h"

// STL
#include <vector>

// Qt
#include <QDoubleSpinBox>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class View;

      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT DoubleSpinBoxEditor : public QDoubleSpinBox, public AbstractEditor
      {
        Q_OBJECT //for slots/signals

      public:

        DoubleSpinBoxEditor(const QModelIndex& index, QWidget* parent = 0);

        virtual ~DoubleSpinBoxEditor();

        virtual QVariant getValue();

      signals:

        void dataValueChanged(QWidget* widget, const Property& prop);

      protected slots:

        virtual void onValueChanged(double d);

      protected:

        virtual void changeEditorData(const QModelIndex& index);
      };
    }
  }
}

#endif



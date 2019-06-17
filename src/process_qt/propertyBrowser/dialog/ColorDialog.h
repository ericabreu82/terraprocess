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
  \file ColorDialogOutside.h
   
  \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_DIALOG__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_DIALOG__

#include "src/process_qt/Config.h"

// TerraLib
#include <terralib/geometry/Envelope.h>

// STL
#include <vector>

// Qt
#include <QCloseEvent>
#include <QDialog>
#include <QEvent>

class QColor;
class QString;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class ColorWidget;
      class Property;

      /*!
      \brief

        \ingroup propertyBrowser

      */
      class TERRAPROCESSQTEXPORT ColorDialog : public QDialog
      {
        Q_OBJECT //for slots/signals

      public:

        ColorDialog(QWidget* parent);

        virtual ~ColorDialog();

        virtual void init();
        
        virtual void setCurrentColor(const QColor& color);

        virtual QColor getCurrentColor() const;

        static QColor getColor(const QColor& initial, QWidget* parent, const QString& title);

      signals:

        void updateProperty(Property prop);

      public slots:

        void  accept();

        void on_okPushButton_clicked();

        void on_closePushButton_clicked();

      protected:

        virtual void  closeEvent(QCloseEvent* event);

        virtual bool event(QEvent* e);

      protected:

        bool          m_okClicked;
        ColorWidget* m_colorWidget;
      };
    }
  }
}

#endif

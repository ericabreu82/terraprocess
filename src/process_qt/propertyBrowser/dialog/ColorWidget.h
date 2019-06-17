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
\file ColorWidget.h

\brief ...
*/
#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_WIDGET__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_WIDGET__

#include "src/process_qt/Config.h"

// Qt includes
#include <QWidget>

class QColor;
class QColorDialog;

namespace te
{
  namespace qt
  {
    namespace widgets
    {
      class HorizontalSliderWidget;
    }
  }
}

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
      \class ColorWidget

      \brief ...
      */
      class TERRAPROCESSQTEXPORT ColorWidget : public QWidget
      {
        Q_OBJECT

      public:

        ColorWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);

        virtual ~ColorWidget();

        virtual void setColor(const QColor& color);

        virtual QColor getColor() const;

      private:

        QColorDialog* m_colorDialog;
        te::qt::widgets::HorizontalSliderWidget* m_sliderWidget;
        bool                                      m_propagateColorUpdate;
      };
    }
  }
}

#endif

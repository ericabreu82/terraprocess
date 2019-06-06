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
  \file terraprocess/src/process_qt/builder/BuilderMainWindow.h

  \brief It contains the main window for TerraProcess Builder Application.
*/

#ifndef __TERRAPROCESS_PROCESSQT_BUILDER_BUILDERMAINDWINDOW__
#define __TERRAPROCESS_PROCESSQT_BUILDER_BUILDERMAINDWINDOW__

#include "src/process_qt/Config.h"

// Qt Includes
#include <QMainWindow>

namespace Ui
{
  class BuilderMainWindowForm;
}

namespace tr
{
  namespace processQt
  {
    namespace builder
    {
      /*!
        \class BuilderMainWindow
       
        \brief A main window for TerraProcess Builder application.
      */
      class TERRAPROCESSQTEXPORT BuilderMainWindow : public QMainWindow
      {
        Q_OBJECT

        public:

          /*! \brief Default constructor. */
          BuilderMainWindow(QWidget* parent = 0);

          /*! \brief Default destructor. */
          ~BuilderMainWindow();

        private:

          Ui::BuilderMainWindowForm* m_ui;
      };
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_BUILDER_BUILDERMAINDWINDOW__
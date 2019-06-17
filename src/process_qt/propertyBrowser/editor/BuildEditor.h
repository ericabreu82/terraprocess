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
  \file BuildEditor.h
   
  \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_BUILD_EDITOR__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_BUILD_EDITOR__

#include "src/process_qt/Config.h"

// STL
#include <vector>

class QWidget;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class AbstractEditor;
      class EditorFactoryParamsCreate;

      /*!
      \brief

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT BuildEditor
      {
      public:
        /*!
          \brief Constructor
        */
        BuildEditor();

        /*!
          \brief Destructor
        */
        virtual ~BuildEditor();

        /*!
          \brief Method to build a editor to a property inside a cell of QTreeWidget.

          \param vprops properties

          \return new editor
        */
        virtual AbstractEditor* buildEditor(const EditorFactoryParamsCreate& params);
      };
    }
  }
}

#endif



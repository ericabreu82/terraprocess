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
  \file AbstractEditor.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_EDITOR__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ABSTRACT_EDITOR__ 

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// Qt
#include <QModelIndex>
#include <QVariant>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {

      class EnumType;
      class ContextPropertyEditor;

      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT AbstractEditor
      {
      public:

        AbstractEditor(const QModelIndex& index, EnumType* type, ContextPropertyEditor* context = 0);

        virtual ~AbstractEditor();

        virtual void setEditorData(const QModelIndex& index);

        tr::processQt::propertyBrowser::Property getProperty();

        virtual QVariant getValue() = 0;

        virtual EnumType* getType();

        /*!
          \brief Value acquired after registration via meta type that QVariant recognizes objects of type tr::processQt::propertyBrowser::Property

          \return role value of tr::processQt::propertyBrowser::Property
        */
        int getRole();

      protected:

        /*
          \brief Checks if the data type is expected and set the new value in editor.
        */
        virtual void changeEditorData(const QModelIndex& index) = 0;

      protected:

        tr::processQt::propertyBrowser::Property m_property;
        EnumType* m_dataType;
        ContextPropertyEditor* m_context;
      };
    }
  }
}

#endif


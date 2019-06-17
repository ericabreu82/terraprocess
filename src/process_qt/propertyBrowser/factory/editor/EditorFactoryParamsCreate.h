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
  \file EditorFactoryParamsCreate.h
   
  \brief Parameters to create a new editor. 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_FACTORY_PARAMS_CREATE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_FACTORY_PARAMS_CREATE__

#include "src/process_qt/Config.h"

// TerraLib
#include <terralib/common/AbstractParameters.h>

// STL
#include <vector>

// Qt
#include <QModelIndex>

class QWidget;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class EnumType;
      class ContextPropertyEditor;
      class Property;
      /*!
      \brief Parameters to create a new tool.

      \ingroup propertyBrowser

      */
      class TERRAPROCESSQTEXPORT EditorFactoryParamsCreate : public te::common::AbstractParameters
      {
      public:


        /*! \brief Copy constructor. */
        EditorFactoryParamsCreate(const EditorFactoryParamsCreate& rhs);

        /*!
          \brief Constructor

          \param view
        */
        EditorFactoryParamsCreate(const QModelIndex& index, const std::vector<Property>& vprops,
          ContextPropertyEditor* context, QWidget* parent = 0);

        /*!
          \brief Destructor
        */
        virtual ~EditorFactoryParamsCreate();

        te::common::AbstractParameters* clone() const;

        void reset() throw(te::common::Exception);

        std::vector<Property> getProperties() const;

        /*!
          \brief Returns the QModelIndex of the QTreeWidget

          \return QModelIndex
        */
        QModelIndex getModelIndex() const;

        QWidget* getParent();

        ContextPropertyEditor* getContextPropertyEditor();

      protected:

        std::vector<Property>           m_vprops;
        QModelIndex                     m_index; //!< Model Index from QTreeWidget
        ContextPropertyEditor* m_context;
        QWidget* m_parent;
      };
    }
  }
}

#endif


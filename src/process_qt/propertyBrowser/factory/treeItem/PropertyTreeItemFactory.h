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
  \file PropertyTreeItemFactory.h

  \brief This is the abstract factory for tree items.
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE_ITEM_FACTORY__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE_ITEM_FACTORY__

#include "src/process_qt/Config.h"

// TerraLib
#include <terralib/common/ParameterizedAbstractFactory.h>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class PropertyTreeItem;
      class PropertyTreeItemFactoryParamsCreate;
      /*!
        \class EditorFactory

        \brief This is the abstract factory for tree items.

        It will create objects of type AbstractEditor and will pass
        parameters of type PropertyTreeItemFactoryParamsCreate to their factories constructors.

        \note The caller of the method make will take the ownership of the returned tool.

      */
      class TERRAPROCESSQTEXPORT PropertyTreeItemFactory : public te::common::ParameterizedAbstractFactory<PropertyTreeItem, std::string, PropertyTreeItemFactoryParamsCreate>
      {
      public:

        /*! \brief Virtual destructor. */
        virtual ~PropertyTreeItemFactory();

      protected:

        /*!
        \brief It creates the factory.

        The key of a ToolFactory is a string.

        \param factoryKey The key that identifies the factory.
        */
        PropertyTreeItemFactory(const std::string& factoryKey);
      };
    }
  }
}

#endif

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
  \file PropertyTreeItem.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE_ITEM__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE_ITEM__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// STL
#include <vector>

// Qt
#include <QTreeWidgetItem>

class QVariant;
class QString;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class EnumType;
      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT PropertyTreeItem : public QTreeWidgetItem
      {
      public:

        PropertyTreeItem(Property& prop, QTreeWidgetItem* parent = 0);

        virtual ~PropertyTreeItem();

        virtual void setData(int column, int role, const QVariant& value);

        Property getProperty();

        virtual void setPropertyValue(QVariant variant);

        virtual void refresh(int column, int role, QString name, QVariant value, QTreeWidgetItem* childItem);

        virtual void refreshChild(int column, int role, QString name, QVariant value);

        EnumType* getDataType();

        int getDataRole();

      protected:

        virtual void setChildData(QTreeWidgetItem* childItem, int column, int role, QVariant value);

      protected:

        Property  m_property;
      };
    }
  }
}

#endif



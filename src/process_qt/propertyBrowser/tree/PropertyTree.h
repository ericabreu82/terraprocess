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
  \file PropertyTree.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_TREE__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Property.h"

// STL
#include <vector>

// Qt
#include <QTreeWidget>

class QTreeWidgetItem;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class PropertyDelegate;

      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT PropertyTree : public QTreeWidget
      {
        Q_OBJECT //for slots/signals

      public:

        PropertyTree(PropertyDelegate* delegate, QWidget* parent = 0);

        virtual ~PropertyTree();

        virtual void setProperties(std::vector<tr::processQt::propertyBrowser::Property> vprops);

        virtual void load(std::vector<tr::processQt::propertyBrowser::Property> props);

        virtual QTreeWidgetItem* createNewRow(tr::processQt::propertyBrowser::Property prop, QTreeWidgetItem* parent = 0);

        void clearAll();

        virtual void propertyTreeItemChanged(QTreeWidgetItem* item, int column);

      signals:

        void propertiesChanged(const tr::processQt::propertyBrowser::Property& prop);

      protected slots:

        /*!
          \brief Goes into editing mode when a item in a column is pressed with the mouse.
        */
        void onCheckEdit(QTreeWidgetItem* item, int column);

      protected:

        void configTree(int numberColumns);

        virtual QTreeWidgetItem* findTopParent(QTreeWidgetItem* currentItem, QTreeWidgetItem* parentItem);

      protected:

        std::vector<tr::processQt::propertyBrowser::Property>   m_vprops;
        int                                 m_columns;
        int                                 m_nameColumn;
        int                                 m_valueColumn;
        bool                                m_loading;
      };
    }
  }
}

#endif


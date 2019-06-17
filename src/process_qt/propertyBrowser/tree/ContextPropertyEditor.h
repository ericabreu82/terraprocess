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
  \file ContextPropertyEditor.h
   
   \brief 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_CONTEXT_PROPERTY_BROWSER__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_CONTEXT_PROPERTY_BROWSER__

#include "src/process_qt/Config.h"

// Qt
class QStringList;

namespace tr
{
  namespace processQt
  {
    namespace graphics
    {
      class Scene;
    }
    namespace propertyBrowser
    {
      class EnumType;
      class AbstractProxy;
      
      /*!
      \brief

      \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT ContextPropertyEditor
      {
      public:

        ContextPropertyEditor(AbstractProxy* proxy, tr::processQt::graphics::Scene* scene);

        virtual ~ContextPropertyEditor();

        AbstractProxy* getProxy();
        
      protected:

        AbstractProxy* m_proxy;
        tr::processQt::graphics::Scene* m_scene;
      };
    }
  }
}

#endif


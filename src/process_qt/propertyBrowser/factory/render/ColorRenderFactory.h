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
  \file ColorRenderFactory.h

  \brief This is the concrete factory for create renders.
 */

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_RENDER_FACTORY__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_COLOR_RENDER_FACTORY__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/factory/render/RenderFactory.h"

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class RenderFactoryParamsCreate;
      class AbstractRender;
      /*!
        \class ColorEditorFactory

        \brief This is the concrete factory for create color renders.

        \sa EditorFactory, ParameterizedAbstractFactory, AbstractEditor
      */
      class TERRAPROCESSQTEXPORT ColorRenderFactory : public RenderFactory
      {
      public:

        /*! It register the factory in the abstract dictionary. */
        ColorRenderFactory();

        /*! \brief Destructor. */
        ~ColorRenderFactory();

      protected:

        /*!
          \brief It creates a new create line item tool.

          \return It returns create line item tool.
        */
        AbstractRender* build(RenderFactoryParamsCreate params);
      };

    }
  }
}

#endif 


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
  \file RenderFactoryParamsCreate.h
   
  \brief Parameters to create a new render. 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_FACTORY_PARAMS_CREATE__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_FACTORY_PARAMS_CREATE__

#include "src/process_qt/Config.h"

// TerraLib
#include <terralib/common/AbstractParameters.h>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
      \brief Parameters to create a new render.

      \ingroup propertyBrowser

      */
      class TERRAPROCESSQTEXPORT RenderFactoryParamsCreate : public te::common::AbstractParameters
      {
      public:


        /*! \brief Copy constructor. */
        RenderFactoryParamsCreate(const RenderFactoryParamsCreate& rhs);

        /*!
          \brief Constructor

          \param view
        */
        RenderFactoryParamsCreate();

        /*!
          \brief Destructor
        */
        virtual ~RenderFactoryParamsCreate();

        te::common::AbstractParameters* clone() const;

        void reset() throw(te::common::Exception);
      };
    }
  }
}

#endif


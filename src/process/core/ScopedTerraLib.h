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
  \file terraprocess/src/process/core/ScopedTerraLib.h

  \brief Utility class used to start TerraLib for a specific scope
*/

#ifndef __TERRAPROCESS_PROCESS_CORE_SCOPEDTERRALIB_H
#define __TERRAPROCESS_PROCESS_CORE_SCOPEDTERRALIB_H

// TerraLib
#include "src/process/Config.h"

namespace tr
{
  namespace process
  {
    namespace core
    {
      class TERRAPROCESSEXPORT ScopedTerraLib
      {
        public:

          /** @name Initializer Methods
          *  Methods related to instantiation and destruction.
          */
          //@{

          /*! \brief Default constructor. */
          ScopedTerraLib(bool loadPlugins);

          /*! \brief Destructor. */
          ~ScopedTerraLib();

          //@}

        protected:

          /*! \brief Load TerraLib Plugins . 
            
            \note Hardcoded plugins list. Only datasource plugins will be loaded.
          
          */
          void loadTerraLibPlugins();
      };
    } // end namespace core
  }   // end namespace process
}     // end namespace tr

#endif  // __TERRAPROCESS_PROCESS_CORE_SCOPEDTERRALIB_H




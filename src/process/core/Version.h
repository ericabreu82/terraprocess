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
  \file terraprocess/src/process/core/Version.h

  \brief Utility class for system versioning.
*/

#ifndef __TERRAPROCESS_PROCESS_CORE_VERSION_H
#define __TERRAPROCESS_PROCESS_CORE_VERSION_H

// TerraLib
#include "src/process/Config.h"

// STL
#include <string>

namespace tr
{
  namespace process
  {
    namespace core
    {
      class TERRAPROCESSEXPORT Version
      {
        public:

          static int majorNumber();

          static int minorNumber();

          static int patchNumber();

          static std::string releaseStatus();

          static std::string buildDate();

          static std::string asString();

          static int asInt();

        private:

          Version();

          ~Version();
      };
    } // end namespace core
  }   // end namespace process
}     // end namespace tr

#endif  // __TERRAPROCESS_PROCESS_CORE_VERSION_H




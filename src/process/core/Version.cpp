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
  \file terraprocess/src/process/core/Version.cpp

  \brief Utility class for system versioning.
*/

#include "src/process/core/Version.h"

// TerraProcess Includes
#include "src/Version.h"

// STL
#include <cassert>

int tr::process::core::Version::majorNumber()
{
  return TERRAPROCESS_VERSION_MAJOR;
}

int tr::process::core::Version::minorNumber()
{
  return TERRAPROCESS_VERSION_MINOR;
}

int tr::process::core::Version::patchNumber()
{
  return TERRAPROCESS_VERSION_PATCH;
}

std::string tr::process::core::Version::releaseStatus()
{
  assert(TERRAPROCESS_VERSION_STATUS);

  return std::string(TERRAPROCESS_VERSION_STATUS);
}

std::string tr::process::core::Version::buildDate()
{
  assert(__DATE__ " " __TIME__);

  return std::string(__DATE__ " " __TIME__);
}

std::string tr::process::core::Version::asString()
{
  assert(TERRAPROCESS_VERSION_STRING);

  return std::string(TERRAPROCESS_VERSION_STRING);
}

int tr::process::core::Version::asInt()
{
  return TERRAPROCESS_VERSION;
}


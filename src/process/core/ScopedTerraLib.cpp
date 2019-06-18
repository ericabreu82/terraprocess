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
  \file terraprocess/src/process/core/ScopedTerraLib.cpp

  \brief Utility class used to start TerraLib for a specific scope
*/

#include "src/process/core/ScopedTerraLib.h"

// TerraLib Includes
#include <terralib_buildconfig.h>
#include <terralib/common/TerraLib.h>
#include <terralib/core/plugin.h>
#include <terralib/core/utils.h>

tr::process::core::ScopedTerraLib::ScopedTerraLib(bool loadPlugins)
{
  TerraLib::getInstance().initialize();

  if (loadPlugins)
  {
    loadTerraLibPlugins();
  }
}

tr::process::core::ScopedTerraLib::~ScopedTerraLib()
{
  TerraLib::getInstance().finalize();
}

void tr::process::core::ScopedTerraLib::loadTerraLibPlugins()
{
  te::core::PluginInfo info;

  std::string plugins_path = te::core::FindInTerraLibPath("share/terralib/plugins");

#ifdef TERRALIB_MOD_POSTGIS_ENABLED
  info = te::core::JSONPluginInfoSerializer(plugins_path + "/te.da.pgis.teplg.json");
  te::core::PluginManager::instance().insert(info);
  te::core::PluginManager::instance().load(info.name);
#endif

#ifdef TERRALIB_MOD_GDAL_ENABLED
  info = te::core::JSONPluginInfoSerializer(plugins_path + "/te.da.gdal.teplg.json");
  te::core::PluginManager::instance().insert(info);
  te::core::PluginManager::instance().load(info.name);
#endif

#ifdef TERRALIB_MOD_OGR_ENABLED
  info = te::core::JSONPluginInfoSerializer(plugins_path + "/te.da.ogr.teplg.json");
  te::core::PluginManager::instance().insert(info);
  te::core::PluginManager::instance().load(info.name);
#endif
}

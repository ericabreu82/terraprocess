##################################################################################
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
#
#  Description: ProcessQt CMake script for the TerraProcess build system.
#
#  Author: Eric Silva Abreu <eric.abreu@gmail.com>
##################################################################################

if(WIN32)
  add_definitions(-DTERRAPROCESSQTDLL)
endif()

# terraprocess/src/process_qt
file(GLOB TERRAPROCESS_PROCESSQT_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/*.cpp)
source_group("Header Files"  FILES ${TERRAPROCESS_PROCESSQT_HDR_FILES})
source_group("Source Files"  FILES ${TERRAPROCESS_PROCESSQT_SRC_FILES})

# terraprocess/src/process_qt/builder
file(GLOB TERRAPROCESS_PROCESSQT_BUILDER_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/builder/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_BUILDER_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/builder/*.cpp)
source_group("Header Files\\Builder"  FILES ${TERRAPROCESS_PROCESSQT_BUILDER_HDR_FILES})
source_group("Source Files\\Builder"  FILES ${TERRAPROCESS_PROCESSQT_BUILDER_SRC_FILES})

file(GLOB TERRAPROCESS_PROCESSQT_BUILDER_UI_FILES  ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/builder/ui/*.ui)
source_group("UI Files\\Builder"  FILES ${TERRAPROCESS_PROCESSQT_BUILDER_UI_FILES})

# terraprocess/src/process_qt/propertyBrowser/graphics
file(GLOB TERRAPROCESS_PROCESSQT_GRAPHICS_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/graphics/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_GRAPHICS_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/graphics/*.cpp)
source_group("Header Files\\Graphics"  FILES ${TERRAPROCESS_PROCESSQT_GRAPHICS_HDR_FILES})
source_group("Source Files\\Graphics"  FILES ${TERRAPROCESS_PROCESSQT_GRAPHICS_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/graphics
file(GLOB TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/graphics/core/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/graphics/core/*.cpp)
source_group("Header Files\\Graphics\\Core"  FILES ${TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_HDR_FILES})
source_group("Source Files\\Graphics\\Core"  FILES ${TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_SRC_FILES})


# terraprocess/src/process_qt/model
file(GLOB TERRAPROCESS_PROCESSQT_MODEL_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/model/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_MODEL_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/model/*.cpp)
source_group("Header Files\\Model"  FILES ${TERRAPROCESS_PROCESSQT_MODEL_HDR_FILES})
source_group("Source Files\\Model"  FILES ${TERRAPROCESS_PROCESSQT_MODEL_SRC_FILES})

file(GLOB TERRAPROCESS_PROCESSQT_MODEL_UI_FILES  ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/model/ui/*.ui)
source_group("UI Files\\Model"  FILES ${TERRAPROCESS_PROCESSQT_MODEL_UI_FILES})

# terraprocess/src/process_qt/propertyBrowser
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/*.cpp)
source_group("Header Files\\Property Browser"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_HDR_FILES})
source_group("Source Files\\Property Browser"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/editor
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/editor/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/editor/*.cpp)
source_group("Header Files\\Property Browser\\Editor"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_HDR_FILES})
source_group("Source Files\\Property Browser\\Editor"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/enum
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/enum/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/enum/*.cpp)
source_group("Header Files\\Property Browser\\Enum"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_HDR_FILES})
source_group("Source Files\\Property Browser\\Enum"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/property
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/property/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/property/*.cpp)
source_group("Header Files\\Property Browser\\Property"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_HDR_FILES})
source_group("Source Files\\Property Browser\\Property"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/proxy
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/proxy/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/proxy/*.cpp)
source_group("Header Files\\Property Browser\\Proxy"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_HDR_FILES})
source_group("Source Files\\Property Browser\\Proxy"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/render
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/render/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/render/*.cpp)
source_group("Header Files\\Property Browser\\Render"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_HDR_FILES})
source_group("Source Files\\Property Browser\\Render"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/tree
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/tree/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/tree/*.cpp)
source_group("Header Files\\Property Browser\\Tree"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_HDR_FILES})
source_group("Source Files\\Property Browser\\Tree"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/factory
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/*.cpp)
source_group("Header Files\\Property Browser\\Factory"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_HDR_FILES})
source_group("Source Files\\Property Browser\\Factory"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/factory/editor
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/editor/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/editor/*.cpp)
source_group("Header Files\\Property Browser\\Factory\\Editor"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_HDR_FILES})
source_group("Source Files\\Property Browser\\Factory\\Editor"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/factory/render
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/render/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/render/*.cpp)
source_group("Header Files\\Property Browser\\Factory\\Render"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_HDR_FILES})
source_group("Source Files\\Property Browser\\Factory\\Render"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/factory/treeItem
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/treeItem/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/factory/treeItem/*.cpp)
source_group("Header Files\\Property Browser\\Factory\\Tree Item"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_HDR_FILES})
source_group("Source Files\\Property Browser\\Factory\\Tree Item"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_SRC_FILES})

# terraprocess/src/process_qt/propertyBrowser/factory/dialog
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/dialog/*.h)
file(GLOB TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process_qt/propertyBrowser/dialog/*.cpp)
source_group("Header Files\\Property Browser\\Dialog"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_HDR_FILES})
source_group("Source Files\\Property Browser\\Dialog"  FILES ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_SRC_FILES})


include_directories(
  SYSTEM ${terralib_INCLUDE_DIRS}
  SYSTEM ${terralib_DIR}
  SYSTEM ${Boost_INCLUDE_DIR}
  SYSTEM ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}
  SYSTEM ${CMAKE_BINARY_DIR}
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# uic'ing
QT5_WRAP_UI(TERRAPROCESSQT_GEN_HDR_FILES ${TERRAPROCESS_PROCESSQT_BUILDER_UI_FILES} 
                                         ${TERRAPROCESS_PROCESSQT_MODEL_UI_FILES})
									  
set(TERRAPROCESSQT_FILES ${TERRAPROCESS_PROCESSQT_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_BUILDER_HDR_FILES} ${TERRAPROCESS_PROCESSQT_BUILDER_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_GRAPHICS_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_GRAPHICS_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_GRAPHICS_CORE_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_MODEL_HDR_FILES} ${TERRAPROCESS_PROCESSQT_MODEL_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_HDR_FILES} ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_EDITOR_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_ENUM_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROXY_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_RENDER_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_TREE_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_EDITOR_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_RENDER_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FACTORY_TREE_ITEM_SRC_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_HDR_FILES}
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_DIALOG_SRC_FILES}
					     ${TERRAPROCESSQT_GEN_HDR_FILES})
						 
add_library(terraProcessQt SHARED ${TERRAPROCESSQT_FILES})

qt5_use_modules(terraProcessQt Core Gui Widgets Svg PrintSupport)

target_link_libraries(terraProcessQt 
									terralib_mod_color
								    terralib_mod_common
								    terralib_mod_core
								    terralib_mod_dataaccess
								    terralib_mod_datatype
								    terralib_mod_geometry
								    terralib_mod_maptools
								    terralib_mod_memory
								    terralib_mod_qt_widgets
								    terralib_mod_srs
								    terralib_mod_symbology
								    terralib_mod_filter
									${Boost_LIBRARIES})
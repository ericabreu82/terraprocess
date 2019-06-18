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
#  Description: Builder CMake script for the TerraProcess build system.
#
#  Author: Eric Silva Abreu <eric.abreu@gmail.com>
##################################################################################

file(GLOB TERRAPROCESS_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/builder/*.h)
file(GLOB TERRAPROCESS_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/builder/*.cpp)
source_group("Header Files"  FILES ${TERRAPROCESS_HDR_FILES})
source_group("Source Files"  FILES ${TERRAPROCESS_SRC_FILES})

include_directories(
  SYSTEM ${terralib_INCLUDE_DIRS}
  SYSTEM ${terralib_DIR}
  SYSTEM ${Boost_INCLUDE_DIR}
  SYSTEM ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}
  SYSTEM ${CMAKE_BINARY_DIR}
)

set(TERRAPROCESS_FILES ${TERRAPROCESS_HDR_FILES} ${TERRAPROCESS_SRC_FILES})

add_executable(terraProcessBuilder ${TERRAPROCESS_FILES})

qt5_use_modules(terraProcessQt Core Gui Widgets Svg PrintSupport)

target_link_libraries(terraProcessBuilder 
									terraProcess
									terraProcessQt
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

if(WIN32 AND MSVC)
  set_target_properties(terraProcessBuilder PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
  set_target_properties(terraProcessBuilder PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
  set_target_properties(terraProcessBuilder PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  set_target_properties(terraProcessBuilder PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  
  string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()
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
#  Description: Runner CMake script for the TerraProcess build system.
#
#  Author: Eric Silva Abreu <eric.abreu@gmail.com>
##################################################################################

file(GLOB TERRAPROCESS_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/runner/*.h)
file(GLOB TERRAPROCESS_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/runner/*.cpp)
source_group("Header Files"  FILES ${TERRAPROCESS_HDR_FILES})
source_group("Source Files"  FILES ${TERRAPROCESS_SRC_FILES})

include_directories(
  SYSTEM ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}
)

set(TERRAPROCESS_FILES ${TERRAPROCESS_HDR_FILES} ${TERRAPROCESS_SRC_FILES})

add_executable(terraProcessRunner ${TERRAPROCESS_FILES})

target_link_libraries(terraProcessRunner terraProcess)

if(WIN32 AND MSVC)
  set_target_properties(terraProcessRunner PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
  set_target_properties(terraProcessRunner PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
  set_target_properties(terraProcessRunner PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  set_target_properties(terraProcessRunner PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  
  string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()
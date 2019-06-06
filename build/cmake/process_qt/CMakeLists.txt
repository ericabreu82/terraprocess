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


include_directories(
  SYSTEM ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}
  SYSTEM ${CMAKE_BINARY_DIR}
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# uic'ing
QT5_WRAP_UI(TERRAPROCESSQT_GEN_HDR_FILES ${TERRAPROCESS_PROCESSQT_BUILDER_UI_FILES} 
                                         ${TERRAPROCESS_PROCESSQT_MODEL_UI_FILES})
									  
set(TERRAPROCESSQT_FILES ${TERRAPROCESS_PROCESSQT_HDR_FILES} ${TERRAPROCESS_PROCESSQT_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_BUILDER_HDR_FILES} ${TERRAPROCESS_PROCESSQT_BUILDER_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_MODEL_HDR_FILES} ${TERRAPROCESS_PROCESSQT_MODEL_SRC_FILES} 
						 ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_HDR_FILES} ${TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_SRC_FILES} 
					     ${TERRAPROCESSQT_GEN_HDR_FILES})
						 
add_library(terraProcessQt SHARED ${TERRAPROCESSQT_FILES})

qt5_use_modules(terraProcessQt Core Gui Widgets)

target_link_libraries(terraProcessQt)
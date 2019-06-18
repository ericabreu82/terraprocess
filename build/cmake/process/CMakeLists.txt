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
#  Description: Process CMake script for the TerraProcess build system.
#
#  Author: Eric Silva Abreu <eric.abreu@gmail.com>
##################################################################################

if(WIN32)
  add_definitions(-DTERRAPROCESSDLL)
endif()

# terraprocess/src/process
file(GLOB TERRAPROCESS_PROCESS_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/*.h)
file(GLOB TERRAPROCESS_PROCESS_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/*.cpp)
source_group("Header Files"  FILES ${TERRAPROCESS_PROCESS_HDR_FILES})
source_group("Source Files"  FILES ${TERRAPROCESS_PROCESS_SRC_FILES})

# terraprocess/src/process/core
file(GLOB TERRAPROCESS_PROCESS_CORE_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/core/*.h)
file(GLOB TERRAPROCESS_PROCESS_CORE_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/core/*.cpp)
source_group("Header Files\\Core"  FILES ${TERRAPROCESS_PROCESS_CORE_HDR_FILES})
source_group("Source Files\\Core"  FILES ${TERRAPROCESS_PROCESS_CORE_SRC_FILES})

# terraprocess/src/process/operations
file(GLOB TERRAPROCESS_PROCESS_OPERATIONS_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/operations/*.h)
file(GLOB TERRAPROCESS_PROCESS_OPERATIONS_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/operations/*.cpp)
source_group("Header Files\\Operations"  FILES ${TERRAPROCESS_PROCESS_OPERATIONS_HDR_FILES})
source_group("Source Files\\Operations"  FILES ${TERRAPROCESS_PROCESS_OPERATIONS_SRC_FILES})

# terraprocess/src/process/serialization
file(GLOB TERRAPROCESS_PROCESS_SERIALIZATION_HDR_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/serialization/*.h)
file(GLOB TERRAPROCESS_PROCESS_SERIALIZATION_SRC_FILES ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/process/serialization/*.cpp)
source_group("Header Files\\Serialization"  FILES ${TERRAPROCESS_PROCESS_SERIALIZATION_HDR_FILES})
source_group("Source Files\\Serialization"  FILES ${TERRAPROCESS_PROCESS_SERIALIZATION_SRC_FILES})

include_directories(
  SYSTEM ${TERRAPROCESS_ABSOLUTE_ROOT_DIR}
  SYSTEM ${terralib_INCLUDE_DIRS}
  SYSTEM ${terralib_DIR}
  SYSTEM ${Boost_INCLUDE_DIR}
  SYSTEM ${CMAKE_BINARY_DIR}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
				  
set(TERRAPROCESS_FILES   ${TERRAPROCESS_PROCESS_HDR_FILES} ${TERRAPROCESS_PROCESS_SRC_FILES} 
                         ${TERRAPROCESS_PROCESS_CORE_HDR_FILES} ${TERRAPROCESS_PROCESS_CORE_SRC_FILES} 
						 ${TERRAPROCESS_PROCESS_OPERATIONS_HDR_FILES} ${TERRAPROCESS_PROCESS_OPERATIONS_SRC_FILES} 
						 ${TERRAPROCESS_PROCESS_SERIALIZATION_HDR_FILES} ${TERRAPROCESS_PROCESS_SERIALIZATION_SRC_FILES} )
						 
add_library(terraProcess SHARED ${TERRAPROCESS_FILES})

target_link_libraries(terraProcess terralib_mod_common
								    terralib_mod_core
									${Boost_LIBRARIES})
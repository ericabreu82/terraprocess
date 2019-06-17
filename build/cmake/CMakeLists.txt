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
#  Description: Main CMake script for the TerraProcess build system.
#
#  Author: Eric Silva Abreu <eric.abreu@gmail.com>
##################################################################################

cmake_minimum_required(VERSION 3.14.3)

project(terraprocess)

#
# main variables for the build script
#

# variables that control the system versioning
set(TERRAPROCESS_VERSION_MAJOR 0)
set(TERRAPROCESS_VERSION_MINOR 1)
set(TERRAPROCESS_VERSION_PATCH 0)
set(TERRAPROCESS_VERSION_STATUS "" CACHE STRING "Define name of installer")
set(TERRAPROCESS_BUILD_NUMBER "" CACHE STRING "Number of build in Jenkins")
set(TERRAPROCESS_VERSION_STRING "${TERRAPROCESS_VERSION_MAJOR}.${TERRAPROCESS_VERSION_MINOR}.${TERRAPROCESS_VERSION_PATCH}")
set(TERRAPROCESS_VERSION "0x000100")
set(TERRAPROCESS_PKG_VERSION ${TERRAPROCESS_VERSION_MAJOR}.${TERRAPROCESS_VERSION_MINOR}.${TERRAPROCESS_VERSION_PATCH})

# TerraLib
set(TERRAPROCESS_TERRALIB_VERSION_MAJOR 5)
set(TERRAPROCESS_TERRALIB_VERSION_MINOR 5)
set(TERRAPROCESS_TERRALIB_VERSION_PATCH 0)

get_filename_component(TERRAPROCESS_ABSOLUTE_ROOT_DIR "../../" ABSOLUTE)

#
# global definitions and includes
#
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER MATCHES ".*clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

# boost
add_definitions(-DBOOST_ALL_NO_LIB -DBOOST_FILESYSTEM_VERSION=3 -DBOOST_UBLAS_TYPE_CHECK=0 -DBOOST_TEST_DYN_LINK)

# cmake policy definitions
#cmake_policy(SET CMP0020 NEW) #Automatically link Qt executables to qtmain target on Windows.
#cmake_policy(SET CMP0007 NEW) #list command no longer ignores empty elements.
#cmake_policy(SET CMP0026 OLD) #Disallow use of the LOCATION target property.
#cmake_policy(SET CMP0042 NEW) #MACOSX_RPATH is enabled by default.
#cmake_policy(SET CMP0043 NEW) #Ignore COMPILE_DEFINITIONS_<Config> properties
#cmake_policy(SET CMP0045 OLD) #Error on non-existent target in get_target_property.
#cmake_policy(SET CMP0053 OLD) #Simplify variable reference and escape sequence evaluation.

#
# Build will generate files into a single folder
#
if((CMAKE_GENERATOR STREQUAL Xcode) OR MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

#
# global configurations
#
if(MSVC)
  set(CMAKE_DEBUG_POSTFIX "d")
  add_definitions(/MP)
endif()

#
# first check of libraries
#
find_package(terralib ${TERRAAMAZON_TERRALIB_VERSION_MAJOR}.${TERRAAMAZON_TERRALIB_VERSION_MINOR}.${TERRAAMAZON_TERRALIB_VERSION_PATCH})

find_package(Boost 1.53.0 REQUIRED system date_time chrono timer filesystem thread unit_test_framework)

if(NOT Boost_FOUND)
  message(FATAL_ERROR "TerraProcess: could not find required Boost libraries!")
endif()

find_package(Qt5 5.12 REQUIRED COMPONENTS Core Gui Widgets Svg PrintSupport)

#
# call cmakefile for each module
#
add_subdirectory(process)

add_subdirectory(process_qt)

add_subdirectory(builder)

add_subdirectory(runner)

# generate Version file
configure_file(${TERRAPROCESS_ABSOLUTE_ROOT_DIR}/src/Version.h.in
               ${CMAKE_BINARY_DIR}/terraprocess_version.h @ONLY)
cmake_minimum_required (VERSION 3.8)

# Internal name of the project
project (Task_0)

# Similar to -fPIC, needed for dynamic libraries
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# This is needed for correct dll linkage in windows
# With this option MSVC will export all functions in shared library 
# and compile .lib file for each dynamic library
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Enable 17 C++ standard
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS -m64)
set(CMAKE_CXX_FLAGS -m64)

if(NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()
if(NOT CMAKE_CONFIGURATION_TYPES)
    set (CMAKE_CONFIGURATION_TYPES Release)
endif()

# Include cmake module ExternalProject needed to build external dependencies
include(ExternalProject)

# Project installation folder
SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Installation)

# RPath folder for dynamic linking 
# Works only on linux
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Folder where all libraries and executables will be put during build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Directly include СMake code for external projects
# include(${CMAKE_CURRENT_SOURCE_DIR}/externalGoogleTest.cmake)

# Commands to invoke CMakeLists.txt files in other folders
add_subdirectory (src)
add_subdirectory(Tests)
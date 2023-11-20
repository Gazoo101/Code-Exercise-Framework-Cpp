# Copyright (c) 2023, Lasse Farnung Laursen
# This code is licensed under MIT license (see LICENSE.txt for details)
# This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp

# cmake_path command requires CMake 3.2 or newer
cmake_minimum_required( VERSION 3.20 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( CodeExerciseFramework )
# Sets ${CMAKE_PROJECT_NAME}

set(CppStandard "C++17" CACHE STRING
  "CppStandard chosen by the user at CMake configure time")

set_property(CACHE CppStandard PROPERTY STRINGS "C++17" "C++20")

cmake_path(SET PATH_APP "${CMAKE_CURRENT_SOURCE_DIR}")
cmake_path(SET PATH_APP_SRC "${PATH_APP}/src")

include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/files_framework.cmake" )
include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/files_tasks.cmake" )

set(FILES_BASE
	"${PATH_APP}/CMakeLists.txt"
	"${PATH_APP}/change.log"
	"${PATH_APP}/README.md"
	
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/files_framework.cmake"
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/files_tasks.cmake"
)

# Merge all the lists of files together...
set(FILES_ALL ${FILES_BASE} ${FILES_FRAMEWORK})
set(FILES_ALL ${FILES_ALL} ${FILES_TASKS})

message(STATUS "Files all")
message(STATUS ${FILES_ALL})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Source Files/" FILES ${FILES_ALL})

add_executable(${CMAKE_PROJECT_NAME} ${FILES_ALL})

include_directories(${PATH_APP_SRC})

if(CppStandard STREQUAL "C++17")
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 17)
elseif(CppStandard STREQUAL "C++20")
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
else()
  message(STATUS "No C++ standard set!")
endif()



set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
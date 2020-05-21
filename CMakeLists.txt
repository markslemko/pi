cmake_minimum_required(VERSION 3.10)

#=== remind us that VCPKG_ROOT is required
if(NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "please set up VCPKG_ROOT=path/to/vcpkg")
endif()


#=== strongly recommend an out of source cmake build
set(DEFAULT_OUT_OF_SOURCE_FOLDER "build")

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    if (NOT EXISTS ${DEFAULT_OUT_OF_SOURCE_FOLDER})
        file(MAKE_DIRECTORY ${DEFAULT_OUT_OF_SOURCE_FOLDER})
    endif()
    message("\nIn-source builds not allowed. Run CMake from the build directory with:\n")
    message("cd build")
    message("cmake ..")
    message("\nto clean up using git:\n")
    message("git clean -fdX\n")
    message(FATAL_ERROR "")
endif()

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

#=== global configs
project(pi)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#=== target configs

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_executable(pi pi.cpp)

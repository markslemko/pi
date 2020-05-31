cmake_minimum_required(VERSION 3.10)

#=== remind us that VCPKG_ROOT is required
if(NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "please set up VCPKG_ROOT=path/to/vcpkg")
endif()

#=== strongly recommend an out of source cmake build
if(NOT DEFINED DEFAULT_OUT_OF_SOURCE_FOLDER)
    set(DEFAULT_OUT_OF_SOURCE_FOLDER "build")
endif()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    if (NOT EXISTS ${DEFAULT_OUT_OF_SOURCE_FOLDER})
        file(MAKE_DIRECTORY ${DEFAULT_OUT_OF_SOURCE_FOLDER})
    endif()
    message("\nIn-source builds have been disallowed. Run CMake from the ${DEFAULT_OUT_OF_SOURCE_FOLDER} directory with:\n")
    message("cd ${DEFAULT_OUT_OF_SOURCE_FOLDER}")
    message("cmake ..")
    message("make")
    message("\nto clean up using git:\n")
    message("git clean -fdX\n")
    message(FATAL_ERROR "")
endif()

#=== connect the vcpkg tool chain 
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

#= PROJECT BEGINS =

#=== global configs
project(pi)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#=== target configs
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_definitions(-DPI_ITERATIVE)
#add_definitions(-DFULL_PARAMETER_RECURSION)
#add_definitions(-DMINIMAL_PARAMETER_RECURSION)

add_executable(pi pi.cpp)

#=== linker directives

#=== recursive version needs a really big stack
if(WIN32)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:536870912")
else()
target_link_libraries(pi PRIVATE "-Wl,--stack,536870912")
endif()
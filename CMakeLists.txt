# libnitroshareapi
# Copyright (C) 2013  Nathan Osman

cmake_minimum_required(VERSION 2.8.9)
project(nitroshareapi)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

include(CXX11.cmake)
check_for_cxx11_compiler(CXX11_COMPILER)
if(NOT CXX11_COMPILER)
    message(FATAL_ERROR "Compiler does not support C++11")
endif()
enable_cxx11()

find_package(Qt5Core    REQUIRED)
find_package(Qt5Network REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

set(SRC
    src/client.cpp)
qt5_wrap_cpp(MOC
    include/nitroshare/api/client.h)

add_library(nitroshareapi SHARED ${SRC} ${MOC})
set_target_properties(nitroshareapi PROPERTIES
    VERSION   ${VERSION}
    SOVERSION ${VERSION_MAJOR})

qt5_use_modules(nitroshareapi Core Network)

install(DIRECTORY include/nitroshare/api
    DESTINATION include/nitroshare)
install(TARGETS nitroshareapi
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/nitroshareapi.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/nitroshareapi.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/nitroshareapi.pc
    DESTINATION lib/pkgconfig)


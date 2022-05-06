cmake_minimum_required(VERSION 3.0)

project(SUM VERSION 1.0)

add_executable(SPENDING main.cpp)

configure_file(main.h main.h)

if(NOT WIN32)
  add_definitions(-DLINUX)
endif()

target_include_directories(SPENDING PUBLIC
                           "${PROJECT_BINARY_DIR}")

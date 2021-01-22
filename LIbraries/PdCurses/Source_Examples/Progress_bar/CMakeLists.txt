cmake_minimum_required(VERSION 3.10)

project(progress_bar)

include_directories(source)

set(LIBS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")

include_directories("${LIBS_PATH}/include")
include_directories("${LIBS_PATH}/include/pdcurses")

IF(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++11")

    link_directories("${LIBS_PATH}/unix/pdcurses/")
ELSE (WIN32)
    set(CMAKE_CXX_FLAGS "/std:c++latest")

    link_directories("${LIBS_PATH}/windows/pdcurses/")
ENDIF (UNIX)

add_executable (progress_bar source/progress_bar.cpp)
    
IF(UNIX)
    target_link_libraries(progress_bar m ncurses)
ELSE (WIN32)
    target_link_libraries(progress_bar pdcurses.lib)
ENDIF (UNIX)

set(CMAKE_BUILD_TYPE Debug)

#Set CMAKE version number
cmake_minimum_required(VERSION 3.0)

#Set project-name and project version number(project-name=SUM)
project(SUM VERSION 1.0)

#Set executable name and cpp files. (EXECUTABLE CPP-FILES)
add_executable(SUM test.cpp)

#Header File
configure_file(test.h test.h)

#Set search path for include files.
target_include_directories(SUM PUBLIC   #(ProjectName PUBLIC)
                           "${PROJECT_BINARY_DIR}"
                           )


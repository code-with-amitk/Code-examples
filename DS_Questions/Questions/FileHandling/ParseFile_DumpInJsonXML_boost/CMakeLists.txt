#Simple CMakeLists file

cmake_minimum_required(VERSION 3.0)
project(Dumper VERSION 1.0)
enable_testing()

set (BOOST_INCLUDE_DIRS /mnt/c/boost_1_75_0/boost)

find_package(Boost REQUIRED COMPONENTS filesystem program_options)
add_subdirectory(Parser)
add_subdirectory(Display)
add_subdirectory(Driver)
add_subdirectory(Tests)

set_target_properties(Driver PROPERTIES FOLDER "cmake")
set_target_properties(Parser PROPERTIES FOLDER "cmake")
set_target_properties(Display PROPERTIES FOLDER "cmake")
#set_target_properties(Tests PROPERTIES FOLDER "cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

target_include_directories(Parser PUBLIC "${PROJECT_BINARY_DIR}"
    PRIVATE ${BOOST_INCLUDE_DIRS}
)

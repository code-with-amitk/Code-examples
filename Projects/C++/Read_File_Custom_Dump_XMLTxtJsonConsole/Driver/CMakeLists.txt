include_directories(
    ${PROJECT_SOURCE_DIR}/Parser/inc
    ${PROJECT_SOURCE_DIR}/Display/inc
    ${PROJECT_SOURCE_DIR}/common/inc
)

SET(ROOT_DIR  ..)
add_executable(Driver main.cpp)
link_directories(${ROOT_DIR}/Parser/Debug)
link_directories(${ROOT_DIR}/Display/Debug)

SET(LIBS Parser Display Boost::filesystem  Boost::program_options)
TARGET_LINK_LIBRARIES(Driver ${LIBS} )

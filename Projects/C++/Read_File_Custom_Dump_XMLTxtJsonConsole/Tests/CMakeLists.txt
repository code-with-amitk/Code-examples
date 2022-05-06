include_directories(
    ${PROJECT_SOURCE_DIR}/Parser/inc
    ${PROJECT_SOURCE_DIR}/Display/inc
    ${PROJECT_SOURCE_DIR}/common/inc
    ${PROJECT_SOURCE_DIR}/Tests/inc
)
SET(ROOT_DIR  ..)

ADD_EXECUTABLE( test1 src/test1.cc )
ADD_TEST( test1 test1 )

link_directories(${ROOT_DIR}/Parser/Debug)
link_directories(${ROOT_DIR}/Display/Debug)

SET(LIBS Display Parser Boost::filesystem Boost::program_options)
TARGET_LINK_LIBRARIES(test1 ${LIBS} )

include_directories(
    ${PROJECT_SOURCE_DIR}/Parser/inc
    ${PROJECT_SOURCE_DIR}/Display/inc
    ${PROJECT_SOURCE_DIR}/common/inc
)
ADD_LIBRARY(Parser STATIC src/Parser.cpp)

include_directories(
	${PROJECT_SOURCE_DIR}/mediator/inc
	${PROJECT_SOURCE_DIR}/seller/inc
	${PROJECT_SOURCE_DIR}/bidder/inc
	${PROJECT_SOURCE_DIR}/common/inc
)

SET(ROOT_DIR  ..)
add_executable(driver main.cpp)
link_directories(${ROOT_DIR}/seller/Debug)
link_directories(${ROOT_DIR}/mediator/Debug)
link_directories(${ROOT_DIR}/bidder/Debug)

SET(LIBS mediator seller bidder)
TARGET_LINK_LIBRARIES(driver ${LIBS})


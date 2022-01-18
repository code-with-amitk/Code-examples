include_directories(
	${PROJECT_SOURCE_DIR}/Meeting/inc
	${PROJECT_SOURCE_DIR}/MeetingRoom/inc
	${PROJECT_SOURCE_DIR}/MeetingScheduler/inc
	${PROJECT_SOURCE_DIR}/Notification/inc
	${PROJECT_SOURCE_DIR}/User/inc
	${PROJECT_SOURCE_DIR}/common/inc
)

SET(ROOT_DIR  ..)
add_executable(Driver main.cpp)
link_directories(${ROOT_DIR}/Meeting/Debug)
link_directories(${ROOT_DIR}/MeetingRoom/Debug)
link_directories(${ROOT_DIR}/MeetingScheduler/Debug)
link_directories(${ROOT_DIR}/Notification/Debug)
link_directories(${ROOT_DIR}/User/Debug)

SET(LIBS Meeting MeetingRoom MeetingScheduler Notification User)
TARGET_LINK_LIBRARIES(Driver ${LIBS})
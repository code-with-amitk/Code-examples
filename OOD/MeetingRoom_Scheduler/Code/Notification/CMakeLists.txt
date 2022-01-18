include_directories(
	${PROJECT_SOURCE_DIR}/Meeting/inc
	${PROJECT_SOURCE_DIR}/MeetingRoom/inc
	${PROJECT_SOURCE_DIR}/MeetingScheduler/inc
	${PROJECT_SOURCE_DIR}/Notification/inc
	${PROJECT_SOURCE_DIR}/User/inc
	${PROJECT_SOURCE_DIR}/common/inc
)

ADD_LIBRARY(Notification STATIC src/Notification.cpp)
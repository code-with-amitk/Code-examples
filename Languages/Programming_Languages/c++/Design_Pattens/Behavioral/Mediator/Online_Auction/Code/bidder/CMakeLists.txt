include_directories(
	${PROJECT_SOURCE_DIR}/seller/inc
	${PROJECT_SOURCE_DIR}/mediator/inc
	${PROJECT_SOURCE_DIR}/bidder/inc
	${PROJECT_SOURCE_DIR}/common/inc
)
ADD_LIBRARY(bidder STATIC src/bidder1.cpp)

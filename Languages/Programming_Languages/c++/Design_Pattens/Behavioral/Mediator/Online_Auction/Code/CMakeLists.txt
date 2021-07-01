cmake_minimum_required(VERSION 3.10)

project(observer)

add_subdirectory(seller)
add_subdirectory(mediator)
add_subdirectory(driver)
add_subdirectory(bidder)

#set_target_properties(common PROPERTIES FOLDER "cmake")
set_target_properties(driver PROPERTIES FOLDER "cmake")
set_target_properties(mediator PROPERTIES FOLDER "cmake")
set_target_properties(seller PROPERTIES FOLDER "cmake")
set_target_properties(bidder PROPERTIES FOLDER "cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

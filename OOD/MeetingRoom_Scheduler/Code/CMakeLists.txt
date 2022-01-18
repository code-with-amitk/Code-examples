# CMakeList.txt : CMake project for Meeting_Scheduler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Meeting_Scheduler")

add_subdirectory(Driver)
add_subdirectory(Meeting)
add_subdirectory(MeetingRoom)
add_subdirectory(MeetingScheduler)
add_subdirectory(Notification)
add_subdirectory(User)

# Add source to this project's executable.
set_target_properties(Driver PROPERTIES FOLDER "cmake")
set_target_properties(Meeting PROPERTIES FOLDER "cmake")
set_target_properties(MeetingRoom PROPERTIES FOLDER "cmake")
set_target_properties(MeetingScheduler PROPERTIES FOLDER "cmake")
set_target_properties(Notification PROPERTIES FOLDER "cmake")
set_target_properties(User PROPERTIES FOLDER "cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# TODO: Add tests and install targets if needed.

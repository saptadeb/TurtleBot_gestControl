cmake_minimum_required(VERSION 2.8.3)
project(fullpkg)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

catkin_package(CATKIN_DEPENDS 
	sensor_msgs
)

set (CMAKE_CXX_STANDARD 11)

find_package(PCL 1.3 REQUIRED COMPONENTS common io)

include_directories(
	include 
	${catkin_INCLUDE_DIRS} 
	${PCL_INCLUDE_DIRS}
)

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(tc src/tc.cpp)
target_link_libraries(tc ${catkin_LIBRARIES} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

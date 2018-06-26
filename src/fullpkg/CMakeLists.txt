cmake_minimum_required(VERSION 2.8.3)
project(fullpkg)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  pcl_conversions
  pcl_ros
  std_srvs
  message_generation
)

add_message_files(
  FILES
  mesg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

find_package(PCL REQUIRED COMPONENTS
  common
  features
  io 
  common
  visualization
)
catkin_package(CATKIN_DEPENDS 
	common_msgs_srvs roscpp rospy std_msgs sensor_msgs std_srvs message_runtime 
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
add_dependencies(tc ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(rns src/rns.cpp)
target_link_libraries(rns ${catkin_LIBRARIES} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})
add_dependencies(rns ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


cmake_minimum_required(VERSION 2.8.3)
project(tl_ros_driver)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(
  tl_driver_node
  src/tl_driver_node.cpp
)
add_library(
  tl_serial_lib
  include/serial/serial.cc
  include/serial/list_ports_linux.cc
  include/serial/unix.cc
  include/serial/win.cc
)
target_link_libraries(
  tl_driver_node
  ${catkin_LIBRARIES}
  ${PROJECT_SOURCE_DIR}/lib/libsoslab_tl_driver.so
  tl_serial_lib
)

add_dependencies(
  tl_driver_node 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

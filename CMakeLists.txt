cmake_minimum_required(VERSION 2.8.3)

project(xsenstoimu)

#add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	sensor_msgs
	xsens_slim
)


include_directories( include
	${catkin_INCLUDE_DIRS}
)

add_executable(xsenstoimu src/xsenstoimu.cpp src/xsenstoimu_utils.cpp)
set_target_properties(xsenstoimu PROPERTIES COMPILE_FLAGS "-O3")
target_link_libraries(xsenstoimu ${catkin_LIBRARIES})

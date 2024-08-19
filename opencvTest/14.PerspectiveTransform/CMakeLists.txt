cmake_minimum_required(VERSION 3.10)
project(PerspectiveTransform)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(PerspectiveTransform main.cpp)
target_link_libraries(PerspectiveTransform ${OpenCV_LIBS})

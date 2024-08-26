cmake_minimum_required(VERSION 3.10)
project(colorRange)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(colorRange main.cpp)
target_link_libraries(colorRange ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.10)
project(threshold)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(threshold main.cpp)
target_link_libraries(threshold ${OpenCV_LIBS})

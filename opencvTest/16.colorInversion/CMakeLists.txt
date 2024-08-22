cmake_minimum_required(VERSION 3.10)
project(colorInversion)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(colorInversion main.cpp)
target_link_libraries(colorInversion ${OpenCV_LIBS})

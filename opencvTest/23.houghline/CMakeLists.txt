cmake_minimum_required(VERSION 3.10)
project(houghline)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(houghline main.cpp)
target_link_libraries(houghline ${OpenCV_LIBS})

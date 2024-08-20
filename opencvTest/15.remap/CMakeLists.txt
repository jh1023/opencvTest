cmake_minimum_required(VERSION 3.10)
project(remap)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(remap main.cpp)
target_link_libraries(remap ${OpenCV_LIBS})

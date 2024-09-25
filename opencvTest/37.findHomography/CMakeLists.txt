cmake_minimum_required(VERSION 3.10)
project(findHomography)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(findHomography main.cpp)
target_link_libraries(findHomography ${OpenCV_LIBS})

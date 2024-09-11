cmake_minimum_required(VERSION 3.10)
project(adaptiveThreshold)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(adaptiveThreshold main.cpp)
target_link_libraries(adaptiveThreshold ${OpenCV_LIBS})

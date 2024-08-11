cmake_minimum_required(VERSION 3.10)
project(backwardMapping)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(backwardMapping main.cpp)
target_link_libraries(backwardMapping ${OpenCV_LIBS})

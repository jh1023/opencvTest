cmake_minimum_required(VERSION 3.10)
project(polygon)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(polygon main.cpp)
target_link_libraries(polygon ${OpenCV_LIBS})

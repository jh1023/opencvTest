cmake_minimum_required(VERSION 3.10)
project(imgResize)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imgResize main.cpp)
target_link_libraries(imgResize ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.10)
project(sobel)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(sobel main.cpp)
target_link_libraries(sobel ${OpenCV_LIBS})

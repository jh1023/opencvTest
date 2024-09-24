cmake_minimum_required(VERSION 3.10)
project(keypointDetection)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(keypointDetection main.cpp)
target_link_libraries(keypointDetection ${OpenCV_LIBS})

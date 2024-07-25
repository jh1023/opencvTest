cmake_minimum_required(VERSION 3.10)
project(imgCrop)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imgCrop main.cpp)
target_link_libraries(imgCrop ${OpenCV_LIBS})

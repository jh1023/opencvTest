cmake_minimum_required(VERSION 3.10)
project(calcHist)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(calcHist main.cpp)
target_link_libraries(calcHist ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.10)
project(template)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(template main.cpp)
target_link_libraries(template ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.10)
project(SVM)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(SVM main.cpp)
target_link_libraries(SVM ${OpenCV_LIBS})

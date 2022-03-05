cmake_minimum_required(VERSION 3.16)
project(Learning_DIP)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Learning_DIP main.cpp 1-Histogram/histogram.cpp 1-Histogram/histogram.h)
target_link_libraries(Learning_DIP ${OpenCV_LIBS})

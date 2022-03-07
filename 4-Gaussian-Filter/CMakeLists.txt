cmake_minimum_required(VERSION 3.16)
project(gaussian_filter)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(gaussian_filter main.cpp gaussian_filter.cpp)
target_link_libraries(gaussian_filter ${OpenCV_LIBS})

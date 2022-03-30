cmake_minimum_required(VERSION 3.16)
project(canny)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(canny sobel.cpp gaussian_filter.cpp canny.cpp main.cpp)
target_link_libraries(canny ${OpenCV_LIBS})

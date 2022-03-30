cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(histogram histogram.cpp)
target_link_libraries(histogram ${OpenCV_LIBS})

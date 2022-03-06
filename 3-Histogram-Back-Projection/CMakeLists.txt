cmake_minimum_required(VERSION 3.16)
project(back_projection)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(back_projection main.cpp back_projection.cpp histogram.cpp)
target_link_libraries(back_projection ${OpenCV_LIBS})

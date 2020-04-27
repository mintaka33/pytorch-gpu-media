cmake_minimum_required(VERSION 3.1)

project(decode)

find_package(OpenCV REQUIRED)

add_executable(decode decode.cpp)

target_link_libraries(decode PRIVATE ${OpenCV_LIBS})

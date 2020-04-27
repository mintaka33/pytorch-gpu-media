

cmake_minimum_required(VERSION 3.1)


project(test)


find_package(OpenCV REQUIRED)


add_executable(test test.cpp)

# Link your application with OpenCV libraries
target_link_libraries(test PRIVATE ${OpenCV_LIBS})

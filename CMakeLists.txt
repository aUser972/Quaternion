cmake_minimum_required(VERSION 3.1)

project(Quaternion)
set(CMAKE_CXX_STANDART 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -g -O0")

file(GLOB MAIN "*.cpp" "*.h")

#find_package(Qt4 4.4.3 REQUIRED QtCore)

add_executable(Quaternion ${MAIN})

#target_link_libraries(Quaternion Qt4::QtCore)

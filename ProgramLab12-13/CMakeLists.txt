cmake_minimum_required(VERSION 3.10)

project(Lab12-13)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

include_directories(include)

add_library(Lab12-13 src/Lab12_100.c)

add_executable(main src/mainLab12.c)

target_link_libraries(main Lab12-13)

set(CMAKE_INSTALL_RPATH ".")
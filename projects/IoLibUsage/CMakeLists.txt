cmake_minimum_required(VERSION 3.17)
project(IoLibUsage)

set(CMAKE_CXX_STANDARD 11)

add_executable(IoLibUsage main.cpp)


add_subdirectory(lib)

target_link_libraries(IoLibUsage lib)
cmake_minimum_required(VERSION 3.17)
project(cpp_pointer)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_pointer main.cpp customStrBlob.cpp customStrBlob.h customStrBlobPtr.cpp customStrBlobPtr.h)
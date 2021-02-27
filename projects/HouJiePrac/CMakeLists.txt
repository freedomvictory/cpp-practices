cmake_minimum_required(VERSION 3.17)
project(HouJiePrac)

set(CMAKE_CXX_STANDARD 11)

#add_executable(HouJiePrac ClassWithPointer/mystring.h ClassWithPointer/string-test.cpp)
#add_executable(HouJiePrac BasicClass/complex.h BasicClass/complex-test.cpp)
#add_executable(HouJiePrac oop/prototypeDesignPattern/Image.h oop/prototypeDesignPattern/ImageChildren.h oop/prototypeDesignPattern/main.cpp)
add_executable(hello oop/Composite/shapes.cpp oop/Composite/shapes.h)
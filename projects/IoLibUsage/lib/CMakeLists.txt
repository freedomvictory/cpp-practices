project(lib)

set(HEADER_FILES
        iooper.h
        )

set(SOURCE_FILES
        iooper.cpp)

add_library(lib STATIC ${SOURCE_FILES} ${HEADER_FILES})



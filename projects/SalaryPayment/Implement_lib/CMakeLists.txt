project(Implement_lib)


set(HEADER_FILES
        Transaction.h
        PayrollDatabase.h
        AddEmployeeTransaction.h
        )

set(SOURCE_FILES
        PayrollDatabase.cpp
        AddEmployeeTransaction.cpp
        )

add_library(Implement_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})






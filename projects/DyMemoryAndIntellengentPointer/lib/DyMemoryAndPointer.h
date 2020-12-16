//
// Created by dingguoliang on 2020/11/24.
//

#ifndef DYMEMORYANDINTELLENGENTPOINTER_DYMEMORYANDPOINTER_H
#define DYMEMORYANDINTELLENGENTPOINTER_DYMEMORYANDPOINTER_H

#include <iostream>
#include <memory>


class OperationAboutPointer{

public:
    static void process(std::shared_ptr<int> ptr){
        return;
    }

    static void testSharedPtrIntoFun();
    static void testProcess();

    static void testUniquePtr();

    static void testDyMemoryArrayStrSplicing();
    static void testReadVariableLenInputStr();
};










#endif //DYMEMORYANDINTELLENGENTPOINTER_DYMEMORYANDPOINTER_H

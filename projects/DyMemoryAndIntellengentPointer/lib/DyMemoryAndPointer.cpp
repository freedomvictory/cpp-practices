//
// Created by dingguoliang on 2020/11/24.
//

#include "DyMemoryAndPointer.h"
using std::shared_ptr;
using std::cout;
using std::make_shared;
using std::unique_ptr;
using std::string;

void OperationAboutPointer::testSharedPtrIntoFun()
{
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    int new_p = *p;
    cout << "[testSharedPtrIntoFun] (log) first new_p: " << new_p;

    process(shared_ptr<int>(p.get()));
    new_p = *p;
    cout << "[testSharedPtrIntoFun] (log) second new_p:" << new_p;
}

void OperationAboutPointer::testProcess()
{
    //auto p = new int();
    auto sp = make_shared<int>();

    process(sp);

    auto out = *sp;
    cout << "[testProcess] (log) out:" << out;



}

void OperationAboutPointer::testUniquePtr()
{

    unique_ptr<string> p1(new string("hello"));
    unique_ptr<string> p2(p1.release());
    string src = *p2;
    cout << "[testUniquePtr] (log) p2:" << src;



}

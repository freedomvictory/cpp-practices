//
// Created by dingguoliang on 2020/11/24.
//

#include "DyMemoryAndPointer.h"
#include <vector>
using std::shared_ptr;
using std::cout;
using std::make_shared;
using std::unique_ptr;
using std::string;
using std::vector;
using std::allocator;

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
//12.23 
void OperationAboutPointer::testDyMemoryArrayStrSplicing()
{
    char *p = new char[256];
    string a = "hello";
    string b = "world";

    int i = 0;
    for(auto c : a)
    {
        p[i] = c;
        ++i;
    }
    for(auto c : b)
    {
        p[i] = c;
        ++i;
    }
    //p[i] = 0;

    std::cout << "[testDyMemoryArrayStrSplicing] (log) p : " << p << std::endl;
    delete [] p;
}
//12.24
void OperationAboutPointer::testReadVariableLenInputStr()
{
    int len = 0;
    char c;
    std::cout << "Please Input string length:";
    std::cin >> len;
//    std::cin.ignore();
    //std::cin >> c;
    std::cin.get(c);
    char *str = new char[len + 1];
    std::cin.get(str, len + 1);
    std::cout << "str : " << str << "\n";
}

void readInput(vector<int> *arg)
{
    std::cout << "Please input some nums:" ;
    //TODO:

}
void OperationAboutPointer::testVectorDirectMemoryManage()
{
    vector<int>* v = new vector<int>();

}

void OperationAboutPointer::testAllocator()
{
    allocator<string> alloc;
    int n = 5;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while(std::cin >> s && q != p+n)
    {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;
    q = p;
    for(int i = 0; i < size; i++)
    {
        cout  << *q << ",";
        q++;
    }
    cout << std::endl;

    while(q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, size);


}



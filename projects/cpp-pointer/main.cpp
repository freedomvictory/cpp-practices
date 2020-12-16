#include <iostream>
#include <fstream>
#include "customStrBlob.h"
#include "customStrBlobPtr.h"

using std::ifstream;

static void test1_customStrBlob(void)
{
    customStrBlob b1;
    {
        customStrBlob b2 {"hi", "hello", "this"};
        b1 = b2;
        b2.push_back("about");
    }
    std:: cout << "[test1_customStrBlob] (log) last element of b1 :" << b1.back();
}


static void test_readInputFileToCustomStrBlob(void)
{
    ifstream myfile("example.txt");
    customStrBlob b;
    string line;
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            b.push_back(line);
        }
    }

    auto p = b.begin();
    for (customStrBlob::size_type pos = 0; pos != b.size(); ++pos, p.incr())
    {
        std::cout << "[test] (log) b's content:" << p.deref() << "\n";
    }






    //TODO:
    //read every line contents from file , and write it into customStrBob.



}

static void testStdOut()
{
    for (int i = 0 ; i < 10; i++)
    {
        std::cout << "the result is " << i << "And Let's continue";
    }
    std::cout << "it's over";

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //test1_customStrBlob();
    test_readInputFileToCustomStrBlob();



    return 0;
}

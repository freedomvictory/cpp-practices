#include <iostream>
#include "customStrBlob.h"


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



int main() {
    std::cout << "Hello, World!" << std::endl;
    test1_customStrBlob();



    return 0;
}

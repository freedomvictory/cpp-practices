#include <iostream>
#include "convhelper.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    ConvHelper<int> f(2);
    std::string format = "array";
    f.setStrFormat(format);
    f.setBigEndian(true);
    std::cout << f.result() << std::endl;
    return 0;
}

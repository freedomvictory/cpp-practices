#include <iostream>
#include <vector>


struct X {
    X() 
    {
        std::cout << "X()" << std::endl;
    }
    X(const X&)
    {
        std::cout << "X(const X&)" << std::endl; 
    }
    X& operator=(const X&)
    {
        std::cout << "operator=(const X&)" << std::endl; 
        return *this;
    }
    ~X()
    {
        std::cout << "~X()" << std::endl; 
    }
};

void Test_A(X a)
{

}

void Test_B(X& b)
{

}



int main(int argc, char** argv)
{
    X x;
    std::cout << "-------1---------" << std::endl;
    Test_A(x);
    std::cout << "-------2--------" << std::endl;
    Test_B(x);
    std::cout << "-------3--------" << std::endl;
    std::vector<X> xs; 
    xs.push_back(x);
    std::cout << "-------4--------" << std::endl;
    X h; 
    h = x;
    std::cout << "-------5--------" << std::endl;
    X* t = new X(); 
    delete t;
    std::cout << "-------6--------" << std::endl;

    return 0;
}
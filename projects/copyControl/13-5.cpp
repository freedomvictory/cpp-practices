#include <iostream> 

// practice 13-5 
//copy constructor basic 


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0){}

    HasPtr(const HasPtr &h) : ps(new std::string(*(h.ps))), i(h.i){};
    void PrintPs();


private:
    std::string *ps;
    int i; 
};

void HasPtr::PrintPs()
{
    std::cout << *(this->ps);
}


int main(int argc, char **argv)
{
    HasPtr a("hello");

    HasPtr b = a; 
    b.PrintPs();

}
#include <iostream> 

// practice 13-8 
//copy assignment operator basic 


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0){}

    HasPtr(const HasPtr &h) : ps(new std::string(*(h.ps))), i(h.i){};
    HasPtr& operator=(const HasPtr &r);
    void PrintPs();


private:
    std::string *ps;
    int i; 
};

void HasPtr::PrintPs()
{
    std::cout << *(this->ps);
}

HasPtr& HasPtr::operator=(const HasPtr &r)
{
    auto newps = new std::string(*r.ps);
    delete ps;
    this->i = r.i;
    this->ps = newps;
    return *this; 
}



int main(int argc, char **argv)
{
    HasPtr p1("world");
    p1 = p1;
    p1.PrintPs();

}
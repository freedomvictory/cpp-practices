#include <iostream> 

//practice 13-15 and 13-16 
class Numbered
{
public:
    Numbered():mysn(sn++){}
    Numbered(const Numbered& r):mysn(sn++){}
    int gotmysn() const 
    {
        return mysn;
    }
private:
    static int sn;
    int mysn;  
};

int Numbered::sn = 0; 

void f(Numbered s)
{
    std::cout <<  s.gotmysn() << std::endl; 
}

void F(const Numbered&s)
{
    std::cout <<  s.gotmysn() << std::endl; 
}

int main(int argc, char* argv[])
{
    Numbered a, b = a,  c = b; //0, 1, 2
    f(a); f(b); f(c);
    //output 3, 4, 5
    std::cout << "-------split-------" << std::endl;
    F(a); F(b); F(c); 
    return 0; 
}


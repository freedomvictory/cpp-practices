#include <iostream> 
#include <ostream> 

//13-18 and 13-19 copy control member 
using namespace std; 

class Employee
{
public:
    static int id; 
    Employee():m_id(id++)
    {}
    Employee(string name) :m_name(name), m_id(id++)
    {}
    Employee(const Employee& e):m_name(e.m_name), m_id(id++)
    {}
    Employee& operator=(const Employee& e)
    {
        this->m_name = e.m_name;
        return *this; 
    }
    const string& getName() const {return m_name;}
    int getId() const {return m_id;}
private:
    string m_name; 
    int m_id; 
};

int Employee::id = 0; 


ostream& operator<<(ostream& os, const Employee& e)
{
    os << "name:" << e.getName() << " id:" << e.getId(); 
    return os;     
}

int main(int argc , char* argv[])
{


    Employee a, b("hello");
    cout << a << endl; 
    cout << b << endl; 
    Employee c = b; 
    cout << c << endl; 
    Employee d("world");
    d = b; 
    cout << d << endl; 



    return 0;
}
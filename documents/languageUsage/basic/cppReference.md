# cpp Reference 


## cpp Reference used for function return values  


A `c++` program can be made easier to read and maintain by using references rather than pointers. A c++ function can return a reference in a similar way as it returns a pointer 

When a function returns a reference, it returns an implicit pointer to its return value. This way, a function can be used on the `left side of an assignment statement`.
For example:


```c++ 
#include <iostream>
#include <ctime>
 
using namespace std;
 
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i ) {
   return vals[i];   // return a reference to the ith element
}
 
// main function to call above defined function.
int main () {
 
   cout << "Value before change" << endl;
   for ( int i = 0; i < 5; i++ ) {
      cout << "vals[" << i << "] = ";
      cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // change 2nd element
   setValues(3) = 70.8;  // change 4th element
 
   cout << "Value after change" << endl;
   for ( int i = 0; i < 5; i++ ) {
      cout << "vals[" << i << "] = ";
      cout << vals[i] << endl;
   }
   return 0;
}
```
Running result is 

```
Value before change
vals[0] = 10.1
vals[1] = 12.6
vals[2] = 33.1
vals[3] = 24.1
vals[4] = 50
Value after change
vals[0] = 10.1
vals[1] = 20.23
vals[2] = 33.1
vals[3] = 70.8
vals[4] = 50
```

## 用引用写只读属性 

```cpp
class Employee
{
public:
    Employee()=default; 
    Employee(string name) :m_name(name)
    {}
    //只读属性  
    const string& getName() const {return m_name;}
private:
    string m_name; 
    int m_id; 
};
```

把引用赋值给普通变量，相当于执行一次拷贝构造或拷贝赋值 
```cpp 
Emplyee b("hello");
string name_b = b.getName(); 
```

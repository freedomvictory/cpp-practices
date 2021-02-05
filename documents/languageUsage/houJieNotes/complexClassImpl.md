 

 1. `c/c++` 的不同之处 

 c 缺乏某些关键字。包内的变量，一般设置为全局。所有的函数都能访问 

 c++ 将数据和函数，封装到一起构成了类，从外部访问看不到数据成员 

 2. `template` 简介 


![](images/template.png)


3. 关于`inline`

函数可以指定为 `inline`， 但是对于特别复杂的函数。即使指定为 `inline` ，编译器也因为能力有限，无法把它视为 `inline` 函数。 ？


4. 关于访问级别 access level 

数据成员 最好放到 `private` 中

函数成员根据需要，放到 `public` 或  `private` 中 

5. 构造函数默认实参 
```c++
complex(double r = 0, double i = 0 ) : re(r), im (i)
{
    
    
}
```

6. 构造函数可以放到private 区  

```cpp
class A {
public:
    static A& getInstance();
    setup() { ... }
private:
    A();
    A(const A& rhs);
    ...
}

A& A:getInstance()
{
    static A a;
    return a; 
}
```

用在一种设计模式 `Singleton` , 称之为 `单例` 也就是说只允许用户创造一个这种类型的对象 


7. 应该用 const 时，尽量用 const 

```cpp
class complex
{
public:
    complex(double r = 0, double i = 0)
        :re(i), im(i)
    { }
    double real ()  {return re; }
    double imag ()  {return im; }
    //it should be this 
    // double real () const {return re; }
    // double imag () const {return im; }
private:
    double re, im;
};


// use it : no problem 
{
    complex c1(2, 1);
    cout << c1.real();
    cout << c1.imag(); 
}
//compile error : not ok! 
{
    const complex c1(2 ,1);
    cout << c1.real(); // no const operation ! 
    cout << c1.imag();
}

```

8. 函数参数尽量传递 `reference` ，不要传递 `value`

    以此提高效率，尤其是对于比较大的变量 


9. `const reference` 的含义 

```c++
copmlex &operator += (const complex &);
```

不可以修改传入参数`引用`的 数值 

10. 返回值尽量 `return reference`

11. 相同`class` 的各个`objects` 互为 `friends`

```cpp
class complex 
{
    complex(double r = 0, double i = 0)
        :re(i), im(i)
    { }
    int func(const complex &param)
    {
         //可以直接调用 param 的私有成员 
        return param.re + param.im;
    }
private:
    double re, im; 
}
```

12. 什么时候不可以 `return by reference`

```c++
//ok!
int add(int a , int b)
{
    int c = a + b; 
    return c; 
}
//not ok!
int& add(int a, int b)
{
    int c = a + b;
    return c;
    //when this function return: c will be delete . 
    //so the reference of c , will not valid  
}

//it's ok : like += 
int& assignmentPlus(int* a, const int& b)
{
    *a += b;
    return *a; 
}

```
也就是要看返回的引用对象是否有效  


13. 传递者无需知道接收者是以 `reference` 形式接收 

```cpp
inline complex&
__doapl(complex* ths, const complex& r)
{
    ...
    return *this;
}
inline complex&
complex::operator += (const complex& r)
{
    return __doapl(this, r);
}

//caller 
{
    complex c1(2, 1);
    complex c2(5);
    c2 += c1;  // 调用者，不必知道接收者是以 `reference` 来接收的
}
```
这样会让调用者非常方便。因为 无论是引用还是非引用作为函数参数，调用者的调用函数方式，都不会有什么区别。


14. `opeartor` 成员函数可以有返回值，这样就可以级联运算 

```cpp 
inline complex&
complex::operator += (const complex& r)
{
    return __doapl(this, r);
}
complex c1, c2, c3; 
c1 += c2 += c3
```


15. `operator` 函数 设置为成员或非成员 


具体情况，具体看待 
但是针对与某些情况，最好写成非成员函数。像下面的例子 


```cpp
ostream&
operator << (ostream &os, const complex &x)
{
    return os << '(' << real(x) << ','
              << imag(x) << ')';
}
```

很明显 `ostream` 是标准库的一部分。一开始不可能把所有的各种类型的输出操作符，都考虑在标准库的类设计中。因此设计成非成员函数，就成了一个很好的选择。 



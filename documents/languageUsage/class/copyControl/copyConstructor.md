# 拷贝构造函数 

## what is copy constructor

它是一个构造函数，第一个参数是改类的引用，其他参数有默认值。

```c++
class Foo{
public:
    Foo();
    Foo(const Foo&); //拷贝构造函数 
    //...
}
```

## synthetic copy constructor 

如果我们没有为自己的类定义一个拷贝构造函数，那么编译器会为我们定义一个。称之为`合成拷贝构造函数`

一般合成拷贝构造函数会将类的参数成员，逐个拷贝到正在创建的对象中。如成员是类，则调用改类的拷贝构造函数，如是内置类型则直接拷贝，如是数组，则会逐个元素地拷贝。

让我们来看`Sales_data` 的例子 `合成的拷贝构造函数` 等价与下边的代码。

```c++
class Sales_data{
public:
    //与合成的拷贝构造函数的等价声明
    Sales_data(const Sales_data &);
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0 
};

//合成的拷贝构造函数的等价实现
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue)
    { }
```



## when to call the copy constructor 


1. 运用 `=` 定义变量时
2. 将一个对象作为实参传递给一个函数的非引用类型的形参
3. 从一个返回类型为非引用类型的函数返回一个对象

```c++
string dots(10, '.'); //直接初始化
string s2 = dots;     //拷贝初始化
string null_book = "9-999-9999"; //拷贝初始化: 先`隐式转换`再拷贝
string nines = string (100, '9');//拷贝初始化
```

```c++ 
string strSplicing(string a, string b)
{
    return a + b; 
} 

string left = "hello";
string right = "world";
auto result = strSplicing(left, right); //执行拷贝操作
```
如上例，调用 `strSplicing` 时会执行3次`copy` 操作， 拷贝实参`left`, `right`, `result` 拷贝返回结果
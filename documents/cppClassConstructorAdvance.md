# CPP 构造函数高阶 



## 1. 构造函数初始值列表 

```c++
class ConstRef{
public: 
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
}

ConstRef::ConstRef(int ii)
{
   i = ii;
   ci = ii; //error 
   ri = i;  //error 
}
```

目前这个构造函数存在错误。 

1. `const` 变量的赋值应该用初始值列表
2. `引用类型`的值也必须在初始值列表里初始化  

**NOTE** 

构造函数的初始值列表，用于给类内变量初始化。而构造函数体，则是给变量赋值，不是初始化。**我们要多使用初始值列表给变量初始化**这样能避免一些意想不到的错误 

所以构造函数的正确写法如下：

```c++
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }
```


## 2. 构造函数成员初始化的顺序 


构造函数成员的初始化顺序是按照在头文件中，声明的成员变量的顺序变量确定的。

```c++
class X{
    int i; 
    int j;
public:
    X(int val) : j(val), i(j){}
}
```

以上代码中，`X`类数据成员的初始化顺序为`先i后j`.根据构造函数初始值列表 `i被初始化为j， j被初始化为val`. 但是因为一开始j是未定义的值，所以这样会引发错误 

**NOTE**

`最好令构造函数初始值的顺序与成员声明的顺序保持一致。而且要尽量避免使用某些成员初始化其他成员。` 


## 3.委托构造函数 


```c++
class Sales_data {
    public :
    //非委托构造函数 
    Sales_data(std::string s, unsigned cnt, double price):
     bookNo(s), units_sold(cnt), revenue(cnt*price) 
     {}

    //其余构造函数全部委托给另一个构造函数 
    Sales_data() :Sales_data("", 0, 0) {}
    Sales_data(std::string s) :Sales_data(s, 0, 0) {} 
    
    //这一个构造函数调用了上面的无参数的委托构造函数 
    Sales_data(std::Istream &is) : Sales_data() 
    {read(is, *this);}

}
```

`所谓委托构造函数就是 一个构造函数对于变量的初始化，交由其他构造函数来做，这边是委托构造函数。`

**托构造函数调用时的执行顺序为：**

```
1. 执行受委托构造函数初始值列表 
2. 执行受委托构造函数函数体 
3. 执行委托者的函数体 
```

## 4.默认构造函数 


一般使用一下语句来使用默认构造函数类初始化变量 

```c++
Sales_data obj; 
```

这说明obj对象没有传入任何参数，这将执行默认构造函数 

如果按照以下方式定义，则定义了一个函数 

```c++
Sales_data obj();
```

















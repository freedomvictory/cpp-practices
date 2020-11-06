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












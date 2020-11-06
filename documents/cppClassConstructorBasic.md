# CPP 类构造函数 



## Instruction  

构造函数在类内定义。用于初始化类内的成员。它有2个特点 
`无返回值` ， `名称和 类名相同`


## what is `synthetic Default constructor`

```c++

class Sales_data{
    std::string isbn() const{
        return bookNo;
    }
    Sales_data& combine (const Saled_data&);
    double avg_price() const;
    

    std::string bookNo;
    unsigned unit_s_sold = 0; 
    double revenue = 0.0;
}

Sales_data total;
Sales_data trans; 

```

如果一个类没有并**没有定义任何构造函数**。 那么定义对象时，编译器就会自动为其生成合成的默认构造函数。

默认构造函数，会通过以下方式，初始化类的数据成员 

1. 如果存在类内初始值，用它来初始化数据成员 
2. 否则默认初始化该成员 

那么如何理解默认初始化：

``` 
也就是给一个变量赋予默认值，这将由变量的类型和变量定义的位置有关系。
```

对于内置类型的变量。定义与任何函数体之外的变量被初始化为0。

**NOTE** 
定义与函数体内部的变量，将不会被初始化。如果执行拷贝，或访问其值，将引发错误 

对于一个复合类型的变量， 将执行复合类型的默认构造函数，进行变量初始化。 

## What will be the problem with  `synthetic Default constructor`


某些类不能依赖于合成的默认构造函数。原因有`3` 

- 只有当类没有声明任何构造函数时，编译器才会自动生产默认构造函数。这意味着某些情况下，类将没有默认构造函数。 

- 对于某些类来说，合成的默认构造函数可能执行错误的操作。 如内置类型和复合类型(指针、数组等) 

- 有的时候编译器不能为某些类合成默认的构造函数。 (如果一个类中包含一个其他类类型的成员且这个成员的类型没有默认构造函数，那么编译器将无法初始化该成员)

## How to write safe constructor code 




```c++
struct Sales_data{

    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, usigned n, double p) :
    bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
}
```

**原则** 

1. 尽量给类内数据成员进行类内值的初始化 。
2. 使用`default` 关键字，可以让编译器帮助我们合成默认构造函数 










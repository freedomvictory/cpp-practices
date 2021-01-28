# 拷贝赋值运算符 

## 它是什么

控制类内的对象如何赋值。下面的例子中 `accum`的值赋值给 `trans` 时，就调用了`拷贝赋值运算符`. `c++` 可以定义 `拷贝赋值运算符`就像定义类内成员函数一样。如果类内没有定义，编译器将为它自动合成一个。

```c++
Sales_data trans, accum;
trans = accum; 
```


## 赋值运算符重点 

当给一个对象赋值的时候。就回调用赋值运算符。赋值运算符成员函数**参数为右侧对象的引用，返回值为左侧对象的引用。**


## 合成拷贝赋值运算符 


合成拷贝赋值运算符是当类没有定义时，由编译器自动生成。它可用来禁止该类型对象的赋值。如果不是这样，那便是将右侧对象的每个非`static` 成员赋予左侧运算对象的对应成员。下面的代码，等价于`Sales_data` 的合成拷贝运算符。 

```c++
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = ruhs.revenue;
    return *this;
}
```
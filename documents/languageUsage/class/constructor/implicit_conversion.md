# Implicit conversion  


## example 


```c++
class Sales_data {
public:
    Sales_data(std::string s, unsigned cnt, double price) : 
        bookNo(s), units_sold(cnt), revenue(cnt * price) {}

        Sales_data(): Sales_data("", 0, 0) {}
        Sales_data(std::string s) : Sales_data(s, 0, 0) {} 
        Sales_data(std::istream &is) : Sales_data() 
        {
            read(is, *this);
        }
        Sales_data &combine(const Sales_data &rhs)
        {
            units_sold += ruhs.units_sold;
            revenue += ruhs.revenue;
            return *this; 
        }
        
private:

    std::string bookNo;
    unsigned units_sold;
    double revenue;           
}

```

如上实例。 依然是 `Sales_data` 用于描述图书销售数据的例子。 

假设我们定义了一个 `item`

```c++
Sales_data item; 
string null_book = "9-999-99999-9";
item.combine(null_book); // string(nullbook) convert to Sales_data
```

以上代码，就进行了隐式转换。 `item.combine(null_book)`, `string` 类型 null book 隐式转换为 `Sales_data` 类型的数据。 <br/>
等价与 `item.combine(Sales_data(null_book))`

## 如何抑制构造函数的隐式转换 

在某些情况下，你可能不想某些函数，做隐式类型转换。 像 

```c++
item.combine(std::cin);
```
它将 `std::cin` 强制转换为 `Sales_data` 。也就是构建一个 `Sales_data` 对象，通过读取标准输入，完成初始化。 而这不是你想要的。你可以这样声明构造函数。  

```c++
explicit Sales_data(std::istream &);  
```

这样就无法进行隐式类型转换，也就是说 `item.combine(std::cin)` 编译时会失败。 

**NOTE** <br/>

`explicit` 构造函数只能用于直接初始化。 



# 友元基础 

Refer `c++ primer 241-242, 250 - 252`

## What is `friend`

类可以让其他类或其他函数访问它的非公有成员，方法就是在类内部声明其他类或函数为`friend`。 一些辅助类或辅助函数可能就是就是该类的友元

## How to use `friend`

```c++
class Sales_data{
//友元声明：
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p * n) { } 
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &); 

private:
    std::string bookNo;       //图书编号
    unsigned units_sold = 0;  //销售数量
    double revenue = 0.0;     //收入 
}
```

如上是一个 `Sales_data` 用于存储图书的销售信息。 我们定义了几个函数 

- `isbn()` 获取图书isbn编号  
- `combine()` 将一个 `sales_data` 对象加到另一个对象上去 
- `add()` 两个 `sales_data` 对象相加 
- `read()` 将数据从 `istream` 读入到 `sales_data` 对象中
- `print()` 将 `sales_data` 对象中的数据，输出到 `ostream` 中 

`add`, `read`, `print` 是友元, 它们不属于类的作用域内， 独立与类的外部，但是可以访问类内的所有成员。<br/>
友元的声明一般是在类的开始前，或结束处。一般是集中声明 

**友元的声明**

在类内部的友元声明只是声明访问权限。而非函数声明。因此我们必须再类外部提供一个函数声明，友元函数才能被使用者所调用。 

## friend used between classes  


现在我们有两个类，`Window_mgr` 和 `Screen` 类。 现在`Windows_mgr` 类添加一个 `clear()` 函数，用于清空屏幕的内容，因此需要访问 `Screen` 类的私有成员 。那么 `Screen` 类 要声明 `window_mgr` 为其友元 

```c++
class Screen{
    friend class Window_mgr; 
    //....
}

class Window_mgr{
public:
    //screen 编号
    using ScreenIndex = std::vector<Screen>::size_type; 
    // clear 指定 screen 
    void clear(ScreenIndex);
private:
    //screen 集合 
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScrrenIndex i)
{
    Screen &s = screen[i];
    //可访问screen 私有成员 
    s.contents = string(s.height * s.width, ' ');    
}
```

另外一个例子：

我们做的练习 `CustomStrBlobPtr` 它是 `CustomStrBlob` 是它的指针，也是友元。 参考 `<c++ primer 5th>` 12.19 练习

[Click it](https://github.com/jaege/Cpp-Primer-5th-Exercises/tree/master/ch12/12.19)


## member function as friend used in class 

上面的关于 `window_mgr` 和 `screen` 的例子，也可以把`clear` 成员函数，单独声明为 友元。参考下面的代码 

```c++ 
class Screen{
    //Window_mgr::clear 必须在 `Screen` 类之前声明 
    friend void Window_mgr::clear(ScrrenIndex);
}
```










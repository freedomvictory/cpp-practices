# weak ptr 虚指针 

## what is it ? 

`weak_ptr` 不控制所指向对象的生存期 ，它指向一个`shared_ptr` 所管理的对象。 它不会改变 `shared_ptr` 的引用计数值。 当对象销毁的时候，跟`weak_ptr` 一点关系都没有，它就是一个弱引用 

## 如何使用它 

```cpp
//定义
auto p = make_shared<int>(42);
weak_ptr<int> wp(p); //wp 弱共享p; p的引用计数未改变 
//使用lock() 访问 
if(shared_ptr<int> np = wp.lock()) //返回真，表示 shared_ptr有效
{
    //TODO: sth 
}
```

## 用途

用于伴随指针。在 `CustomStrBlobPtr` 的例子中，你会看到。


```cpp 
class customStrBlobPtr {
public:
    customStrBlobPtr() : curr(0){ }
    explicit customStrBlobPtr(customStrBlob &c, std::size_t sz = 0) :
    wptr(c.data), curr(sz) {  }

    string& deref() const;
    customStrBlobPtr& incr();
private:

    shared_ptr<vector<string>> check(std::size_t i, const string& msg) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};
```
//练习 12.19 




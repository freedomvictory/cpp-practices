# Combine shared_prt and new() 


## 初始化操作 

```c++
shared_ptr<int> p2(new int(1024));
```
共享指针必须显式初始化，且无法进行强制类型转换 


## 不要混合使用普通指针和智能指针 

```c++

void process(shared_ptr<int> ptr)
{

} //ptr 离开作用域被销毁 

//正确使用process方法
shared_ptr<int> p(new int(42)); //引用计数 1
process(p); //引用计数变为2
int i = *p; //引用计数又变为1 

//错误的操作 
int *x(new int(1024));
process(x); // error: 不能将int* 转换为一个shared_ptr<int>
process<shared_ptr<int>(x)>;
int j = *x;  //error: x内存已经被释放，是个空悬指针 

```

## 慎用get() 

```c++
shared_prt<int> p(new int(42)); //引用计数为1 
int *q = p.get();
{
   auto m = shared_ptr<int>(q);
} //m被释放， 它指向的内存也被释放
int foo = *p;  // 未定义的行为 
```

**NOTE** 

1. 永远不要用get初始化或者赋值另一个智能指针
2. `get()`用来将指针的访问权限传递给代码，只有在确定代码不会delete 指针的情况下，才能使用`get()`

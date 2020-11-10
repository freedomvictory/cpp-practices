# cpp 智能指针


## `shared_ptr`

特点： 允许多个指针，指向同一块内存 

### `shared_prt`初始化 

```c++

//指向一个值为42的int的shared_ptr
shared_ptr<int> p3 = make_shared<int>(42);
//指向一个值为"9999999999" 的 string
shared_ptr<string> p4 = make_shared<string>(10, '9');
//指向一个值初始化的int，即值为0 
shared_ptr<int> p5 = make_shared<int>();

```

**note：**

括号后的参数，填写要与类型的构造函数相匹配



### `shared_ptr` 拷贝和赋值 

```c++
auto p = make_shared<int>(42);
auto q(p);
```

以上代码执行后，`p`和 `q` 将指向相同的对象


每个`shared_ptr` ，其实是一块内存都有一个关联的计数器，也就是`引用计数`。 它就是与这块内存，相关联的指针变量个数。 当拷贝`shared_ptr` 这个数会递增，因为现在多了一个变量引用这块内存。
但当我们给`shared_ptr`变量赋予一个新的值或是`share_ptr`变量被销毁，引用技术就会递减。 一旦`引用计数` 变为0,这块内存就会被自动释放







### `shared_ptr` 自动销毁所管理的对象 


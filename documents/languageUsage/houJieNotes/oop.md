# OOP 

## 类和类之间的关系 

1. Composition 复合
2. Inheritance 继承
3. Delegation 委托

## Composition （复合）关系

所谓 `复合` 即包含关系。即 `has-a`


![](./images/composition.png)

如上例，即是 `Composition` 关系。 类 `queue` 中，包含 `Sequence` 类型的变量 `c`. 


### Adapter 模式 

`adapter` 单词的意思是 适配。 

在上图当中就是`adapter` 模式的体现。`queue` 类中封装的各种操作。其实是直接调用了 `deque<T>` 标准库的操作。也就是说`queue` 类只是对`deque<T>`的操作进行了适配，抽取了几个功能。 `queue` 是一个单边队列， `deque` 是个双边队列。 
  
### Composition 关系下的构造和析构 


![](./images/containter.png)

如上图，`Containter` 包含 `Component`

如果 `Containter` 的构造函数不使用初始化器，编译器将为其合成，也就是会首先调用 `Component` 的 `default` 构造函数，然后才执行自己，所以构造函数是由内而外的。 

```c++
Containter::Container(...) : Component() {}
```

对于析构函数是由外而内的。`Containter`的析构函数会首先执行自己，然后再调用`Component` 的析构函数 
```cpp
Containter::~Container(...){... ~Component()}
```

## Delegation (委托) Composition by reference 

![](./images/delegation.png)

通俗来讲就是 用引用的方式来组合。`String` class 当中有个 指针。类型是`StringRep`. 这个类封装了 字符串的内部实现。 对于用户来讲，会直接调用 `String` class 提供的接口。 这是一种比较灵活的实现方式，`String` class 中的 指针可以指向不同的类型。 从而使用不用的接口 

左下角的图片。是说`a, b, c` 3个变量使用同一个指针，引用了同一块内存。这一块内存存放的字符串为`hello`. 一般再调用下面的代码时，会发生这个事情。

```c++
String a = "hello";
String b = a, c = a; 
```
a, b ,c 的`rep` 变量指向同一块内存。如果此时`a` 的内容又发生变化。会发生`copy on write` ，也就是`写时copy`

## Inheritance(继承)，表示 `is-a`

```cpp
struct _List_node_base
{
    _List_node_base *_M_next;
    _List_node_base *_M_prev;
};

template<typename _Tp>
struct _List_node
    : public _List_node_base
{
    _Tp _M_data;
}
```

![](./images/inheritance.png)

### inheritance 关系下的构造和析构 

![](./images/inhConstruct.png)

如果我们在派生类的构造函数没有写初始化器的相关内容，编译器将为我们默认自动合成。调用基类的默认构造函数。 

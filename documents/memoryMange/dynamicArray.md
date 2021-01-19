# 动态数组 

## NOTE

```
大多数应用应该使用标准库容器而不是动态分配的数组。使用容器更为简单，更不容易出现内存管理错误并且可能有更好的性能
```

## 基础操作 


- 初始化
```c++ 
int *pia = new int[10];//10个默认初始化的int
int *pia2 = new int[10]();  //10个值初始化为0 的 int 
```

- 释放

```c++
delete [] pia;
```
**note**

动态数组释放内存时，一定要在变量前面加上 `[]`。 如果我们在`delete` 一个指向数组的指针时，忽略了`[]`,其行为是未定义的 

## 智能指针和动态数组 

- `unique_ptr`

```c++
unique_ptr<int[]> up(new int[10]);
//使用下标运算符，访问数组元素 
for(size_t i = 0 ; i != 10; ++i)
{
    up[i] = i; 
}

up.release(); //自动用 delete[] 销毁其指针 
```

- `shared_ptr`

如果希望使用 `shared_ptr` 管理动态数组，必须提供自定义的删除器

```
shared_ptr <int> sp(new int[10], [](int *p) {delete [] p;});
```
如果未提供删除器，这段代码将是未定义的。默认情况下， `shared_ptr` 使用 `delete` 销毁它指向的对象而不是 `delete []`

如果要访问数组的元素， 则需要使用 get 获取内置指针来操作。因为 `shared_ptr` 不直接支持动态数组管理这一特性。 
```c++
for (size_t i = 0; i != 10; ++i)
    *(sp.get() + i) = i;
```
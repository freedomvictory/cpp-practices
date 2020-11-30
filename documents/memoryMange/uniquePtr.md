# unique_ptr

## 特点 

一个`unique_ptr` 独占它所指向的对象。某一个时刻只能有一个`unique_ptr` 指向一个给定对象。当`unique_ptr` 被销毁时，它所指向的对象也被销毁 



## 初始化 

```c++
unique_ptr<double> p1; //定义
unique_ptr<int> p2(new int(42)); //定义并初始化 
```

**NOTE**

`unique_ptr` 不支持普通的拷贝和赋值 

```c++
unique_ptr<string> p1(new string("hello"));
unique_ptr<string> p2(p1); //错误， 不支持拷贝
unique_ptr<string> p3 = p2; //错误， 不支持赋值 
```


## 把一个`unique_ptr`指向的对象转移到另一个 `unique_ptr`



```c++
unique_ptr<string> p1(new string("hello"));
unique_ptr<string> p2(p1.release());

unique_ptr<string> p3(new string("Trex"));
p2.reset(p3.release());
```


`release()`
    解决unique_ptr 与 内存的绑定关系。释放unique_ptr内存。返回之前内存的指针  

`reset()`释放unique_ptr指向的内存。重置指针值，让它指向新的内存 

## 向 `unique_ptr` 传递删除器 

```c++
void f(destination &d)
{
    connection c = connect(&d);
    //当p被销毁时，连接会被关闭 
    unique_ptr<connection, decltype(end_connection)*>
        p(&c, end_connection);
        //使用连接
        //当f退出时(即使是由于异常而退出), connecion 会被正确关闭
}
```




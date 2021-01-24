## cpp常规指针 


## 动态分配内存


```c++
int *pi = new int(1024); //pi 指向值为1024的内存
string *ps = new string(5, '9'); // ps 指向值为"99999"的内存
string *m = new string(); //m 指向值为空字符串的内存
```

**NOTE:** 
对于动态分配的对象，最好进行值初始化。否则可能执行默认构造函数，进行默认初始化


## 释放动态内存 

```c++
int *pi = new int(1024);
delete pi;
pi = nullptr; //重置为空，防止被错误调用 
```

**NOTE**

使用new 和delete 管理动态内存存在3个常见问题 
1. 忘记delete 内存
2. 使用已经释放掉的对象
3. 同一块内存释放2次 

# allocator 

## allocator 的优势 

allocator 也用来分配一大块内存。传统的 `new` 将内存分配和对象构造组合在一起。 `delete` 也是如此。而 `allocator` 将内存分配和对象构造分离开来 。这将有助于我们这块内存上`按需构造对象`。 



## allocator 基础使用 

```c++
allocator<string> alloc;
int n = 5;
auto const p = alloc.allocate(n); //分配内存 
auto q = p;
string s;
while(std::cin >> s && q != p+n)
{
    alloc.construct(q++, s);  //构造对象(从标准输入中，读取字符串)
}
const size_t size = q - p;
q = p;
for(int i = 0; i < size; i++)
{
    cout  << *q << ",";
    q++;
}
cout << std::endl;

while(q != p)
    alloc.destroy(--q);    //析构 (可以复用内存，来保存其他`string`)
alloc.deallocate(p, size); //释放内存 

```

## 拷贝和填充未初始化内存 


```c++

vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
//分配比 vi 中元素所占用空间大一倍的动态内存 
auto p = alloc.allocate(vi.size() * 2);
//拷贝vi中的元素构造从p开始的元素。返回的 q指向最后一个构造元素之后的位置  
auto q = uninitialized_copy(vi.begin(), vi.end(), p);
//将剩余元素初始化为42 
uninitialized_fill_n(q, vi.size(), 42);
```

**NOTE** 

传递给 `uninitialized_copy` 的目的位置迭代器，***必须指向未构造的内存***
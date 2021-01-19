# string stream 


## istringstream 

`istringstream`  可以从string中读取数据。

我们来看一个例子。现在我们有一个文件，里面存储一些人和他们的电话号码。有些人有一个电话号码，有些人有多个。 现在这个文件就是这样。 

```
moragan 2015552368 8625550123 
drew 8435550130
lee 6095550132 2015550745 8005550000
```
我们现在读取这个文件，得到姓名和电话号码，存储到一个结构体中。代码如下：


```cpp

struct PersonInfo{
    string name;
    vector<string> phones;
}

string line, word;
vector<PersonInfo> people; 

while(getline(cin, line))
{
    PersonInfo info;
    //将line的内容，加载到stream 中去 
    istringstream record(line);
    // so that , we can read line , using stream 
    record >> info.name;
    while(record >> word)
        info.phones.push_back(word);
    people.push_back(info);
}

```



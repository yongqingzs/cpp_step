## cpp开发相关
1. cpp编译器(g++)比gcc更加严格
- 当函数返回类型存在时，必须有返回值 -> 在gcc中可以通过编译
- 函数声明必须在定义之前 -> 在gcc中可以通过编译(虽然会产生警告)
2. new/delete
- 与malloc/free的区别(TODO): 猜测malloc/free无法分配对象指针的内存空间
- new分配的动态数组，用sizeof计算数组大小时(arr)，得到的是指针的大小 -> 程序会跟踪分配的内存量，但是这个信息不是公用的
- new初始化对象时，有new必须有delete；new对应于delete，new[]对应于delete[]
3. 返回类型为指针(c同理)
```cpp
int * ptr_return(void)
{
    int arr[] = {1, 2, 3, 4, 5}; 
    int * pt = arr;
    std::cout << "pt in ptr_return: " << pt << std::endl;
    return pt;  // 虽然返回的是指针的地址，但是指针指向的内存空间已经被释放
}
```
4. 引用相关
- 引用无法对数组进行操作
5. 在头文件中定义一个变量，这种情况为什么会报错 -> 在cpp中有“单定义规则”，如果多个文件包含了同一个头文件，那么这个变量就会被定义多次，所以会报错(因为ifndef只是防止头文件被重复包含，而不能防止变量被重复定义)
```cpp
#ifndef _TEST_H_
#define _TEST_H_
double warming = 0.3;
#endif
```


## TODO
1. 函数重载
2. 命名空间
## cpp开发相关
1. cpp编译器(g++)比gcc更加严格
- 当函数返回类型存在时，必须有返回值 -> 在gcc中可以通过编译
- 函数声明必须在定义之前 -> 在gcc中可以通过编译(虽然会产生警告)
2. new/delete
- 与malloc/free的区别(TODO): 猜测malloc/free无法分配对象指针的内存空间
- new分配的动态数组，用sizeof计算数组大小时(arr)，得到的是指针的大小 -> 程序会跟踪分配的内存量，但是这个信息不是公用的
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

## TODO
1. 函数重载
2. 命名空间
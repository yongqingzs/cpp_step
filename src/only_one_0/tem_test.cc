#include <iostream>
template <typename T>
void swap(T &a, T &b);

template <> void swap<double> (double & d1, double & d2);

int main()
{
    void swap_test(void); 
    void swap_test_0(void);

    int type = 1;
    switch (type)
    {
    case 0:
        swap_test();
        break;
    case 1:
        swap_test_0();
        break;
    default:
        break;
    }
    swap_test();
}

template void swap<int> (int &, int &);  // 显式实例化，目的是告诉编译器，会和显式具体化发生冲突
void swap_test(void)
{
    using std::cout, std::endl;
    int a = 10;
    int b = 20;
    cout << "a: " << a << ", b: " << b << endl;
    swap(a, b);
    cout << "After exchange, a: " << a << ", b: " << b;
}

void swap_test_0(void)
{
    using std::cout, std::endl;
    double a = 10.8;
    double b = 20.9;
    cout << "a: " << a << ", b: " << b << endl;
    swap(a, b);
    cout << "After exchange, a: " << a << ", b: " << b;
}

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <> void swap<double> (double & d1, double & d2)
{
    using std::cout, std::endl;
    double temp;
    temp = d1;
    d1 = d2;
    d2 = temp;
    cout << "1111111111" << endl;
}

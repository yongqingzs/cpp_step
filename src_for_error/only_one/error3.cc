// error3.cc -- using an exception
/* 
抛出异常，只有被try块包围的代码才能捕获异常
*/
#include <iostream>
double hmean(double a, double b);

int main()
{
    void error_test_0(void);
    void error_test_1(void);

    int type = 1;
    switch (type)
    {
    case 0:
        error_test_0();
        break;
    case 1:
        error_test_1();
        break;
    default:
        break;
    }
}

double hmean(double a, double b)
{
    if (a == -b)
        throw "bad hmean() arguments: a = -b not allowed";  // 抛出异常，只有被try块包围的代码才能捕获异常
    return 2.0 * a * b / (a + b);
}

void error_test_0(void)
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try { // start of try block
            z = hmean(x, y);
        } // end of try block
        catch (const char * s) // start of exception handler
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        } // end of handler
        std::cout << "Harmonic mean of " << x << " and " << y
            << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
}

void error_test_1(void)
{
    double x = 10.0;
    double y = 6.1;
    double z = hmean(x, y);
    std::cout << "stop\n";
}

#include <iostream>
using namespace std;

int main(void)
{
    int firstref(void);
    int secref(void);
    int swap_test(void);
    int cube_test(void);

    int type = 3;
    switch (type)
    {
        case 0:
            firstref();
            break;
        case 1:
            secref();
            break;
        case 2:
            swap_test();
            break;
        case 3:
            cube_test();
            break;
        default:
            break;
    }
}

int firstref(void)
{
    // firstref.cpp -- defining and using a reference
    int only_int = 55;
    int * p_int; 
    p_int = &only_int;

    int & ref_int = only_int;  // 必须在声明时初始化
    cout << "only_int = " << only_int << endl;
    cout << "*p_int = " << *p_int << endl;
    cout << "ref_int = " << ref_int << endl;
    cout << "=============================" << endl;

    int rats = 101;
    int * pt = &rats;
    int & rodents = *pt;    // rodents is a reference to an int
    int bunnies = 50;
    pt = &bunnies;          // pt now points to bunnies
    cout << "*pt = " << *pt << endl;
    cout << "rodents = " << rodents << endl;
    return 0;
}

int secref(void)
{
    // secref.cpp -- defining and using a reference
    int rats = 101;
    int & rodents = rats;   // rodents is a reference

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;      // can we change the reference?
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    return 0;
}

int swap_test(void)
{   
    void swapr(int & a, int & b);   // a, b are aliases for ints
    void swapp(int * p, int * q);   // p, q are addresses of ints
    void swapv(int a, int b);       // a, b are new variables

    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2);  // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);    // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    return 0;
}

void swapr(int & a, int & b)   // use references
{
    int temp;

    temp = a;   // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int * p, int * q)   // use pointers
{
    int temp;

    temp = *p;  // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)       // try using values
{
    int temp;

    temp = a;   // use a, b for values of variables
    a = b;
    b = temp;
}

int cube_test(void)
{   
    double cube(double a);
    double refcube(double & ra);

    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = recube of " << x << endl;

    // refcube(1);  // error: cannot bind non-const lvalue reference of type ‘double&’ to an rvalue of type ‘double’
    // refcube(1.0);
    int only_int = 10;
    // refcube(only_int);

    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(double & ra)
{
    ra *= ra * ra;
    return ra;
}

double const_refcube(const double & ra)
{
    // ra *= ra * ra;  // error: assignment of read-only reference ‘ra’
    return ra * ra * ra;
}


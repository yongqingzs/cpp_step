// usestok1.cc -- the client program
// compile with stock10.cc
#include <iostream>
#include "stock20.h"

int main(void)
{
    int stock_test(void);
    int stock_test_0(void);
    int stock_test_1(void);
    int stock_test_2(void);
    int stock_test_3(void);
    int stock_ptr(void);

    int type = 5;
    switch (type)
    {
        case 0:
            stock_test();
            break;
        case 1:
            stock_test_0();
            break;
        case 2:
            stock_test_1();
            break;
        case 3:
            stock_test_2();
            break;
        case 4:
            stock_test_3();
            break;
        case 5:
            stock_ptr();
            break;
        default:
            break;
    }
    return 0;
}

int stock_test(void)
{
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0); // syntax 1
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";

    return 0;
}

int stock_test_0(void)
{
    Stock stock1 = Stock();  // default constructor
    stock1.show();

    Stock stock2("Namo");
    stock2.show();

    Stock stock3;
    stock3 = stock2;
    return 0;
}

int stock_test_1(void)
{
    using std::cout;
    Stock stock1 = Stock("stock1", 5, 1.5);  

    Stock stock2 = stock1;
    cout << "location of stock1:" << &stock1 << "\n";
    cout << "location of stock2:" << &stock2 << "\n";
    return 0;
}

int stock_test_2(void)
{
    using std::cout;
    Stock stock1("NanoSmart", 12, 20.0); // syntax 1
    Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2

    stock2 = stock1;

    stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
    return 0;
}

int stock_test_3(void)
{
    // create an array of initialized objects
    Stock stocks[4] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 2, 2.0),
        Stock("Monolithic Obelisks", 4, 50.0),
        Stock("Fleep Enterprises", 1, 100.0)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < 4; st++)
        stocks[st].show();

    // set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < 4; st++)
        top = &top->topval(stocks[st]);  // TODO
    // now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    top->show();
    return 0;
}

int stock_ptr(void)
{
    Stock stock1("stock1_for_ptr");
    Stock * stock_ptr = &stock1;
    stock_ptr->show();
    // std::cout << stock_ptr->shares;
    // std::cout << stock1.shares;
    return 0;
}

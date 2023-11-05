// usebrass1.cc -- testing bank account classes
// compile with brass.cc
#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS = 4;

int main()
{
    void brass_test(void);
    void brass_test_0(void);
    void brass_test_1(void);
    void brass_test_2(void);
    int type = 3;

    switch (type)
    {
        case 0:
            brass_test();
            break;
        case 1:
            brass_test_0();
            break;
        case 2:
            brass_test_1();
            break;
        case 3:
            brass_test_2();
            break;
        default:
            break;
    } 

    return 0;
}

void brass_test(void)
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg account balance: $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
}

void brass_test_0(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                    tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // free memory
    }
    cout << "Done.\n";
}

void brass_test_1(void)
{
    Brass * ptr_0, * ptr_1;
    Brass b1 = Brass("b1", 1, 1.0);
    BrassPlus bp1 = BrassPlus("bp1", 2, 2.0, 2.0, 2.0);
    ptr_0 = &b1;
    ptr_1 = &bp1;
    ptr_0->identity();
    ptr_1->identity();
}

void brass_test_2(void)
{
    Brass b1;
    BrassPlus bp1;
    b1.read_book(1);
    bp1.read_book(2);
    bp1.read_book(2.0);
    bp1.bal_pro_plus(1);
}

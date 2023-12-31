// namesp.cpp -- namespaces
#include <iostream>
#include "namesp.h"

double temp_d = 0.0;

namespace pers
{
    void getPerson(Person & rp)
    {
        std::cout << "Enter first name: ";
        std::cin >> rp.fname;
        std::cout << "Enter last name: ";
        std::cin >> rp.lname;
    }

    void showPerson(const Person & rp)
    {
        std::cout << rp.lname << ", " << rp.fname;
    }
}


namespace debts
{
    void getDebt(Debt & rd)
    {
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }

    void showDebt(const Debt & rd)
    {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }

    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i = 0; i < n; i++)
        {
            total += ar[i].amount;
        }
        return total;
    }
}

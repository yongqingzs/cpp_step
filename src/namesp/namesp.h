// namesp.h
#ifndef NAMESP_H_
#define NAMESP_H_

#include <string>
// create the pers and debts namespaces

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}

#define TEMP_D 11.25
// double temp_d;  // 错误，不能在头文件中定义全局变量
#endif
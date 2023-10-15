// usenmsp.cc -- using namespaces
#include <iostream>
#include "namesp.h"
void other(void);
void another(void);

int main(void)
{
    using debts::Debt;
    using debts::showDebt;
    std::cout << TEMP_D << std::endl;
    Debt golf = {{"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();
    extern double temp_d;
    std::cout << "temp_d: " << temp_d << std::endl;
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);
    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    return;
}

void another(void)
{
    // using pers::Person;
    using debts::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}

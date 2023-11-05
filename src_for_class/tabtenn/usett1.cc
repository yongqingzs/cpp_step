// usett1.cpp -- using base class and derived class
#include <iostream>
#include "tabtenn1.h"

int main(void)
{
    void official_test(void);
    void inherit_test(void);

    int type = 1;
    switch (type)
    {
    case 0:
        official_test();
        break;
    case 1:
        inherit_test();
        break;
    default:
        break;
    }

    return 0;
}

void official_test(void)
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", true);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name(); // derived object uses base method
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player1.Name(); // base object uses base method
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";    
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
}

void inherit_test(void)
{
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    RatedPlayer rplayer2(1212, "Mallory1", "Duck1", true);
    TableTennisPlayer * table_ptr = &rplayer1;
    TableTennisPlayer & table_ref = rplayer2;
    TableTennisPlayer table;
    // RatedPlayer * rated_ptr = &table;

    table_ptr->Name();
    std::cout << "\n";
    table_ref.Name();
}

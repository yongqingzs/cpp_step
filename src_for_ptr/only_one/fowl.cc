// fowl.cc -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>

int main()
{
    void ptr_test_0(void);
    void ptr_test_1(void);
    int type = 1;
    
    switch (type)
    {
    case 0:
        ptr_test_0();
        break;
    case 1:
        ptr_test_1();
        break;
    default:
        break;
    }
    return 0;
}

void ptr_test_0(void)
{
    // auto_ptr is deprecated
    // using namespace std;
    // auto_ptr<string> films[5] =
    // {
    //     auto_ptr<string> (new string("Fowl Balls")),
    //     auto_ptr<string> (new string("Duck Walks")),
    //     auto_ptr<string> (new string("Chicken Runs")),
    //     auto_ptr<string> (new string("Turkey Errors")),
    //     auto_ptr<string> (new string("Goose Eggs"))
    // };
    // auto_ptr<string> pwin;
    // pwin = films[2]; // films[2] loses ownership

    // cout << "The nominees for best avian baseball film are\n";
    // for (int i = 0; i < 5; i++)
    //     cout << *films[i] << endl;
    // cout << "The winner is " << *pwin << "!\n";
    // cin.get();
}

void ptr_test_1(void)
{
    using namespace std;
    shared_ptr<string> films[5] =
    {
        shared_ptr<string> (new string("Fowl Balls")),
        shared_ptr<string> (new string("Duck Walks")),
        shared_ptr<string> (new string("Chicken Runs")),
        shared_ptr<string> (new string("Turkey Errors")),
        shared_ptr<string> (new string("Goose Eggs"))
    };
    shared_ptr<string> pwin;
    pwin = films[2]; // films[2] loses ownership

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;
    cout << "The winner is " << *pwin << "!\n";
    cin.get();
}

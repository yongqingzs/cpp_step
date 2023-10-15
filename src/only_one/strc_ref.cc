// strc_ref.cpp -- using structure references
#include <iostream>
#include <istream>
#include <string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    int strc_ref_test(void);
    int strc_ref_test_0(void);
    int ptr_return_test(void);

    int type = 2;
    switch (type)
    {
    case 0:
        strc_ref_test();
        break;
    case 1:
        strc_ref_test_0();
        break;
    case 2:
        ptr_return_test();
        break;
    default:
        break;
    }
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << " Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

int strc_ref_test(void)
{
    // partial initializations - remaining members set to 0
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    // no initialization
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    // use return value in assignment
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    set_pc(four);

    // ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
    return 0;
}

free_throws & strc_ref_return(free_throws & ft)
{
    return ft;
}

free_throws & strc_ref_return_0(free_throws & ft)
{   
    free_throws newguy;
    newguy = ft;
    // return newguy;  // warning: reference to local variable ‘newguy’ returned [-Wreturn-local-addr]
    return ft;
}

free_throws strc_return(free_throws & ft)
{
    return ft;
}

int strc_ref_test_0(void)
{
    using namespace std;

    free_throws one = {"Ifelsa Branch", 13, 14};

    free_throws & two = strc_ref_return(one);
    free_throws three = strc_return(one);
    free_throws four = strc_ref_return(one);
    free_throws & five = strc_ref_return_0(one);

    cout << "one: " << &one << endl;
    cout << "two: " << &two << endl;
    cout << "three: " << &three << endl;
    cout << "four: " << &four << endl;
    cout << "five: " << &five << endl;
    return 0;
}

int * ptr_return(void)
{
    int arr[] = {1, 2, 3, 4, 5}; 
    int * pt = arr;
    std::cout << "pt in ptr_return: " << pt << std::endl;
    return pt;
}

int ptr_return_test(void)
{   
    int * pt = ptr_return();
    std::cout << "pt in main: " << pt << std::endl;
    std::cout << "*pt in main: " << *pt << std::endl;
    return 0;
}

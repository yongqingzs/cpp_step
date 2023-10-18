// usetime0.cc -- using the first draft of the Time class
// compile usetime0.cc and mytime0.cc together
#include <iostream>
#include "mytime0.h"

int main(void)
{
    int usetime_sum(void);
    int usetime_operator(void);
    int usetime_operator_0(void);
    int time_ptr_test(void);
    int time_ref_test(void);
    int time_friend_test(void);
    Time & time_ref_test_0(void);

    int type = 6;
    switch (type)
    {
    case 0:
        usetime_sum();
        break;
    case 1:
        usetime_operator();
        break;
    case 2:
        usetime_operator_0();
        break;
    case 3:
        time_ptr_test();
        break;
    case 4:
        time_ref_test();
        break;
    case 5:
        time_friend_test();
        break;
    case 6:
        time_ref_test_0();
        break;
    default:
        break;
    }
}

int usetime_sum(void)
{   
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;

    return 0;
}

int usetime_operator(void)
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    return 0;
}

int usetime_operator_0(void)
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}

int time_ptr(Time * t)
{
    using std::cout;
    using std::endl;
    
    t->Show();
    t->Reset(8, 9);
    cout << "\nAfter change: ";
    t->Show();
    return 0;
}

int time_ptr_test(void)
{
    Time t(5, 6);

    time_ptr(&t);
    return 0;
}

int time_ref(Time & t)
{
    using std::cout;
    using std::endl;

    t.Show();
    t.Reset(11, 15);
    cout << "\nAfter change: ";
    t.Show();
    return 0;
}

int time_ref_test(void)
{
    Time t(5, 6);

    time_ref(t);
    return 0;
}

int time_friend_test(void)
{
    Time t_0(5, 6);
    Time t_1 = 2 * t_0;
    std::cout << t_1 << std::endl;
    return 0;
}

Time & time_ref_test_0(void)
{
    Time t_0(5, 6);
    Time & t_1 = t_0;
    return t_1;
}

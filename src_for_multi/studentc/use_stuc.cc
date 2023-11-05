// use_stuc.cc -- using a composite class
#include <iostream>
#include "studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
    void student_test_0(void);
    void studentc_test_1(void);

    int type = 1;
    switch (type)
    {
    case 0:
        student_test_0();
        break;
    case 1:
        studentc_test_1();
        break;
    default:
        break;
    }
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; ++i)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}

void student_test_0(void)
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
}

void studentc_test_1(void)
{
    Student s1(2);
    // Student s2 = 5;  // 将这种构造函数隐藏了
    cout << s1 << endl;
}

// use_stui.cc -- using a class with private inheritance
// compile with studenti.cc
#include <iostream>
#include "studenti.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    void student_test_0(void);
    void studenti_test_1(void);

    int type = 1;
    switch (type)
    {
    case 0:
        student_test_0();
        break;
    case 1:
        studenti_test_1();
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

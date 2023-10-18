// sayings1.cc -- using expanded String class
// compile with string1.cc
#include <iostream>
#include <cstdlib> // (or stdlib.h) for rand(), srand()
#include <ctime> // (or time.h) for time()
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    void string_test(void);
    void string_test_0(void);
    void string_test_1(void);
    void string_test_2(void);

    int type = 1;

    switch (type)
    {
    case 0:
        string_test();
        break;
    case 1:
        string_test_0();
        break;
    case 2:
        string_test_1();
        break;
    case 3:
        string_test_2();
        break;
    default:
        break;
    }
}

void string_test(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    String sayings[ArSize]; // array of objects
    char temp[MaxLen]; // temporary string storage
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
            break; // i not incremented
        else
            sayings[i] = temp; // overloaded assignment
    }
    int total = i; // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;

        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany()
            << " String objects. Bye.\n";
    }
    else
        cout << "No input! Bye.\n";
}

void string_test_0(void)
{
    String s1("s1");
    String s2 = s1;  // copy constructor
    String s3;
    s3 = s1;  // = constructor
    std::cout << "loc of s1: " << &(s1) << '\n';
    std::cout << "loc of s2: " << &(s2) << '\n';
    std::cout << "loc of s3: " << &(s3) << '\n';
}

void string_test_1(void)
{
    String string_test_1_sub(String &s1);
    
    String s1("s1");
    String s2 = string_test_1_sub(s1);  // copy constructor

    std::cout << "end\n";
}

String string_test_1_sub(String &s1)
{
    return s1;
}

void string_test_2(void)
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    String sayings[ArSize]; // array of objects
    char temp[MaxLen]; // temporary string storage
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
            break; // i not incremented
        else
            sayings[i] = temp; // overloaded assignment
    }
    int total = i; // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        // use pointers to keep track of shortest, first strings
        String *shortest = &sayings[0]; // initialize to first object
        String *first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first) // compare values
                first = &sayings[i]; // assign address
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total; // pick index at random
        // use new to create, initialize new String object
        String *favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Not much to say, eh?\n";
    cout << "Bye.\n";
}

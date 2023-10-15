// left.cpp -- string function with a default argument
#include <iostream>

char * left_input(const char * str, int n = 1);
unsigned long left(unsigned long num, unsigned ct = 1);
char * left(const char * str, int n = 1);

int main(void)
{
    int left_test(void);
    int leftover(void);

    int type = 1;
    switch (type)
    {
        case 0:
            left_test();
            break;
        case 1:
            leftover();
            break;
        default:
            break;
    }
}

char * left_input(const char * str, int n)
{
    // This function returns a pointer to a new string
    // consisting of the first n characters in the str string.
    if (n < 0)
    {
        n = 0;
    }

    char * p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
    {
        p[i] = str[i]; // copy characters
    }

    while (i <= n)
    {
        p[i++] = '\0'; // set rest of string to '\0'
    }

    return p;
}

int left_test(void)
{
    using namespace std;
    const int ArSize = 80;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);
    char * ps = left_input(sample, 4);
    cout << ps << endl;
    delete [] ps; // free old string
    ps = left_input(sample);
    cout << ps << endl;
    delete [] ps; // free new string
    return 0;
}

// This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
    {
        return 0; // return 0 if no digits
    }

    while (n /= 10)
    {
        digits++;
    }

    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
        {
            num /= 10;
        }

        return num; // return left ct digits
    }
    else // if ct >= number of digits
    {
        return num; // return the whole number
    }
}

char * left(const char * str, int n)
{
    if (n < 0)
    {
        n = 0;
    }
    char * p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
    {
        p[i] = str[i]; // copy characters
    }
    while (i <= n)
    {
        p[i++] = '\0'; // set rest of string to '\0'
    }
    return p;
}

int leftover(void)
{
    using namespace std;
    const char * trip = "Hawaii!!"; // test value
    char * temp;
    for (int i = 0; i < 10; i++)
    {
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp; // point to temporary storage
    }
    return 0;
}

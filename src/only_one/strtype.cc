#include <iostream>
#include <string>               // make string class available
#include <cstring>              // C-style string library
using namespace std;

int strtype1(void);
int strtype2(void);
int strtype3(void);
int strtype4(void);
int strtype5(void);

int main(void)
{
    int type = 4;
    
     switch (type)
     {
          case 0:
               strtype1();
               break;
          case 1:
               strtype2();
               break;
          case 2:
               strtype3();
               break;
          case 3:
               strtype4();
               break;
          case 4:
               strtype5();
               break;
          default:
               break;
     }
}

int strtype1(void)
{
    char charr1[20];            // create an empty array
    char charr2[20] = "jaguar"; // create an initialized array
    string str1;                // create an empty string object
    string str2 = "panther";    // create an initialized string
    cout << "Enter a kind of feline: ";
    cin >> charr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;                // use cin for input
    cout << "Here are some felines:\n";
    cout << charr1 << " " << charr2 << " "
         << str1 << " " << str2 // use cout for output
         << endl;
    cout << "The third letter in " << charr2 << " is "
         << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
         << str2[2] << endl;    // use array notation
    return 0;
}

int strtype2(void)
{
     // strtype2.cpp -- assigning, adding, and appending
     string s1 = "penguin";
     string s2, s3;
     cout << "You can assign one string object to another: s2 = s1\n";
     s2 = s1;
     cout << "s1: " << s1 << ", s2: " << s2 << endl;
     cout << "You can assign a C-style string to a string object.\n";
     cout << "s2 = \"buzzard\"\n";
     s2 = "buzzard";
     cout << "s2: " << s2 << endl;
     cout << "You can concatenate strings: s3 = s1 + s2\n";
     s3 = s1 + s2;
     cout << "s3: " << s3 << endl;
     cout << "You can append strings.\n";
     s1 += s2;
     cout << "s1 += s2 yields s1 = " << s1 << endl;
     s2 += " for a day";
     cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;
     return 0;
}

int strtype3(void)
{
     // strtype3.cpp -- more string class features
     char charr1[20];
     char charr2[20] = "jaguar";
     string str1;
     string str2 = "panther";
     // assignment for string objects and character arrays
     str1 = str2;                // copy str2 to str1
     strcpy(charr1, charr2);     // copy charr2 to charr1
     // appending for string objects and character arrays
     str1 += " paste";           // add paste to end of str1
     strcat(charr1, " juice");   // add juice to end of charr1
     // finding the length of a string object and a C-style string
     int len1 = str1.size();     // obtain length of str1
     int len2 = strlen(charr1);  // obtain length of charr1
     cout << "The string " << str1 << " contains "
          << len1 << " characters.\n";
     cout << "The string " << charr1 << " contains "
          << len2 << " characters.\n";
     return 0;
}

int strtype4(void)
{
     // strtype4.cpp -- line input
     char charr[20];
     string str;

     cout << "Length of string in charr before input: "
          << strlen(charr) << endl;
     cout << "Length of string in str before input: "
          << str.size() << endl;
     cout << "Enter a line of text:\n";
     // cin.getline(charr, 20);     // indicate maximum length
     cin.getline(charr, 20);     // indicate maximum length
     cout << "You entered: " << charr << endl;
     cout << "Enter another line of text:\n";
     getline(cin, str);          // cin now an argument; no length specifier
     cout << "You entered: " << str << endl;
     cout << "Length of string in charr after input: "
          << strlen(charr) << endl;
     cout << "Length of string in str after input: "
          << str.size() << endl;
     return 0;
}

int strtype5(void)
{
     char site[20] = "house";  // site的长度必须大于house of pancakes
     strcat(site, "of pancakes");
     cout << site << endl;
     cout << R"(FEINIU\n)" << "\n";
     cout << R"+*((FEINIU\n))+*" << "\n";
     return 0;
}

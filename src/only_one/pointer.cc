#include <iostream>
#include <cstring>
#include <vector>
#include <array>
using namespace std;

int main()
{
    int pointer_test(void);
    int pointer_test_0(void);
    int use_new(void);
    int str_ptr(void);
    int struct_ptr(void);
    void delete_test(void);
    int vector_test(void);
    
    int type = 6;
    switch (type)
    {
        case 0:
            pointer_test();
            break;
        case 1:
            pointer_test_0();
            break;
        case 2:
            use_new();
            break;
        case 3:
            str_ptr();
            break; 
        case 4:
            struct_ptr();
            break;
        case 5:
            delete_test();
            break;
        case 6:
            vector_test();
            break;
        default:
            break;
    }
}

int pointer_test(void)
{
    // pointer.cpp -- our first pointer variable
    int updates = 6;        // declare a variable
    int * p_updates;        // declare pointer to an int

    p_updates = &updates;   // assign address of int to pointer

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    return 0;
}

int pointer_test_0(void)
{
    int * pt;
    pt = (int *) 0xB8000000;
    cout << "Value of pt = " << pt << endl;
    return 0;
}

int use_new(void)
{
    // use_new.cpp -- using the new operator
    int nights = 1001;
    int * pt = new int;     // allocate space for an int
    if (pt == NULL) // !PT; NULL; nullptr
    {
        cout << "No memory available\n";
        exit(EXIT_FAILURE);
    }
    *pt = 1001;             // store a value there
    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double * pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there
    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;
    delete(pt);  // free(pt);

    int * psome = new int [10]; // get a 10-int block
    cout << "location of psome: " << &psome << endl;
    cout << "size of psome = " << sizeof(* psome) << endl;  // sizeof(psome[])得到的值是错误的
    int arr_psome[10];
    cout << "size of arr_psome = " << sizeof(arr_psome) << endl;
    delete [] psome;            // free the block
    return 0;
}

int str_ptr(void)
{
    // strptr.cpp -- using pointers to strings
    char animal[20] = "bear";   // animal holds bear
    const char * bird = "wren"; // bird holds address of string
    char * ps;                  // uninitialized

    cout << animal << " and ";  // display bear
    cout << bird << "\n";       // display wren
    // cout << ps << "\n";         // may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    
    // cin >> animal;              // ok if input < 20 chars

    // cin >> ps;                  // too horrible a blunder to try; ps doesn't point to allocated space
    ps = animal;                // set ps to point to string
    cout << ps << "!\n";        // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1];  // get new storage
    strcpy(ps, animal);                 // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;

    cout << "Len of animal: " << strlen(animal) << endl;
    string str_animal = animal;
    str_animal = "rabbit";
    cout << "Len of str_animal: " << str_animal.size() << endl;
    return 0;
}

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int struct_ptr(void)
{
    inflatable * ps = new inflatable;   // allot memory for structure
    // cout << "Enter name of inflatable item: ";
    // cin.get(ps->name, 20);              // method 1 for member access
    // cout << "Enter volume in cubic feet: ";
    // cin >> (*ps).volume;                // method 2 for member access
    // cout << "Enter price: $";
    // cin >> ps->price;

    char str_arr[20];
    strcpy(ps->name, "Glorious Gloria");
    (*ps).volume = 1.88;
    ps->price = 29.99;
    cout << "Name: " << (*ps).name << endl;  // method 2
    cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
    cout << "Price: $" << ps->price << endl; // method 1
    delete ps;                          // free memory used by structure
    return 0;
}

void delete_test(void)
{   
    // delete.cpp -- using the delete operator
    char * getname(void);

    char * name;
    name = getname();   // assign address of string to name
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // memory freed

    name = getname();   // reuse freed memory
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // memory freed again
}

char * getname(void)    // return pointer to new string
{
    char temp[80];      // temporary storage
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1]; // get space to hold name
    strcpy(pn, temp);   // copy name into smaller space
    return pn;          // temp lost when function ends
}

int vector_test(void)
{
    vector<int> vi = {1, 2, 3, 4, 5};
    cout << "vi.size() = " << vi.size() << endl;
    array<int, 5> ai = {1, 2, 3, 4, 5};
    cout << "ai.size() = " << ai.size() << endl;
    return 0;

    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    vector<double> a2(4);   // create vector with 4 elements
    // no simple way to initialize a vector with an array
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    // C++11 -- create and initialize array object
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;    // valid for array objects of same size
    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    return 0;
}

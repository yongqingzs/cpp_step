// external.cc -- external variables
// compile with support.cc
#include <iostream>
#include "support.h" // external variable declarations
using namespace std;
// external variable
double warming = 0.3; // warming defined

static int errors = 5;  // 即使没有extern，也会导致多重定义

// extern int fingers; 

// function prototypes
void update(double dt);
void local();

int main() // uses global variable
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1); // call function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local(); // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";
    cout << "fingers in main: "<< fingers << std::endl;
    return 0;
}

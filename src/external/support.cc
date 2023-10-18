// support.cc -- use external variable
// compile with external.cc
#include <iostream>
#include "support.h" // external variable declarations
extern double warming; // use warming from another file

int errors = 20;

// extern int fingers = 55;

// function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt) // modifies global variable
{
    // extern double warming; // optional redeclaration
    warming += dt; // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
    cout << "fingers in update: "<< fingers << std::endl;
}

void local() // uses local variable
{
    double warming = 0.8; // new variable hides external one
    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the scope resolution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}

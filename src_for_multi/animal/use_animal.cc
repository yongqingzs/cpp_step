#include "animal.h"

int main()
{
    dog d1;
    animal * a1 = &(d1);
    a1->walk(100);
    a1->identity();
}
#include <valarray>
#include <iostream>

using std::valarray;
using std::cout;

int main(void)
{
    double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
    valarray<double> v1;
    valarray<double> v2(8);
    valarray<double> v3(10, 8);
    valarray<double> v4(gpa, 4);
    cout << "max_v4: " << v4.max() << "\n";
}
// mytime0.h -- Time class before operator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_

#include <ostream>

using std::ostream;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time & t) const;
    Time & operator+(const Time & t) const;
    friend Time operator*(double m, const Time & t);
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    void Show() const;

    friend ostream & operator<<(ostream & os, const Time & t);
};

#endif

#ifndef ANIAMAL_H_
#define ANIAMAL_H_

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class animal
{
private:
    string name;
    int size;
public:
    animal() : name("only animal"), size(5) {}
    animal(const string & s, int i) : name(s), size(i) {}
    virtual ~animal() {}
    void walk(int i) const { cout << "animal walk " << i << " steps" << endl; }
    void eat(int i) const { cout << "animal eat " << i << " food" << endl; }
    void call_name(void) const { cout << "name: " << name << endl; }
    virtual void identity(void) const { call_name(); };
};

class dog : public animal
{
private:
    string master_name;
public:
    dog() : animal("dog", 11), master_name("xiaozhuang") {}
    dog(const string & s, int i, const string & m) : animal(s, i), master_name(m) {}
    virtual ~dog() {}
    void walk(int i) const { cout << "dog walk " << i << " steps" << endl; }  // 没有使用继承
    virtual void identity(void) const { call_name(); cout << "master_name: " << master_name << endl; };
};

#endif
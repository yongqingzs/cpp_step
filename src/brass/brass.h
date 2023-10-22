// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <iostream>
#include <string>

// Brass Account Class
class Brass
{
protected:
    double bal_pro = 100;  // 不建议对数据成员使用bal_pro
private:
    std::string fullname;
    long acctNum;
    double balance;
public:
    Brass(const std::string & s = "Nullbody", long an = -1,
          double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {}
    virtual void identity(void) const {std::cout << "Brass" << std::endl;};
    virtual void read_book(int i) const {std::cout << i << std::endl;};
    virtual void read_book(double d) const {std::cout << d << std::endl;};
};

// Brass Plus Account Class
class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500,
              double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; };
    void ResetRate(double r) { rate = r; };
    void ResetOwes() { owesBank = 0; };
    virtual void identity(void) const { std::cout << "BrassPlus" << std::endl; };
    virtual void read_book(int i) const { std::cout << "BrassPlus int: " << i << std::endl; };
    virtual void read_book(double d) const { std::cout << "BrassPlus double: " << d << std::endl; };
    void bal_pro_plus(int i) { bal_pro += i; std::cout << "bal_pro: " << bal_pro << std::endl; };
    void func_0(int i);
};

#endif

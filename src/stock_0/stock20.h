// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

# include <string>

class Stock
{
    private:
        // const int MAX = 10;  // 无法编译通过
        enum {MAX = 10};  // 可以编译通过
        static const int MAX_0 = 10;  // 可以编译通过
        // static const double MAX_1 = 10.1;  // 可以编译通过(c++11)
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        // two constructors
        Stock(void);
        Stock(const std::string & co, long n = 0, double pr = 0.0);
        ~Stock(void); // noisy destructor
        // void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;  // 无法修改对象的成员
        const Stock & topval(const Stock & s) const;
};

#endif

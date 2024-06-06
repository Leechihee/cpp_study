#ifndef STOCK_H_
#define STOCK_H_
#include <iostream>

class Stock{
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = share_val * shares;}
public:
    Stock();
    Stock(const char * co, long n = 0,double pr = 0.0);
    ~Stock();
    void buy(long n, double pr);
    void sell(long n, double pr);
    void update(double pr);
    friend std::ostream & operator<<(std::ostream & os, const Stock & s);
    const Stock & topval(const Stock & s) const;
};

#include "Stock.cpp"
#endif

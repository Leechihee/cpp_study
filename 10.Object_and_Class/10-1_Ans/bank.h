#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <string>

class bank
{
private:
    std::string Bname;
    std::string Baccount;
    unsigned long Bmoney;
public:
    bank();
    bank(const std::string name, const std::string account, unsigned long n);
    ~bank();
    void show() const;
    void inMoney(unsigned long n);
    void outMoney(unsigned long n);
};

#include "bank.cpp"
#endif

#include <iostream>
#include <string>

class bank
{
private:
    std::string name;
    std::string account;
    long long money;
public:
    bank();
    bank(const std::string name, const std::string account, long long n);
    ~bank();
    void show(const bank &b) const;
    void inMoney(const std::string account, long long n);
    void outMoney(const std::string account, long long n);
};

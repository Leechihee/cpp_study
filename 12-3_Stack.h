#include <iostream>

class Stack{
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = share_val * shares;}
public:
    Stack();
    Stack(const char * co, long n = 0,double pr = 0.0);
    ~Stack();
    void buy(long n, double pr);
    void sell(long n, double pr);
    void update(double pr);
    friend std::ostream & operator<<(std::ostream & os, const Stack & s);
    const Stack & topval(const Stack & s) const;
};

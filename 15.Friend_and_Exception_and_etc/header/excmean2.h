#ifndef EXCMEAN_H_
#define EXCMEAN_H_
#include <iostream>
#include <stdexcept>
#include <string>

class error : public std::logic_error{
    double a;
    double b;
public:
    explicit error(double x = 0, double y = 0, const std::string & s = "Error!") : a(x), b(y), std::logic_error(s) {}
    virtual void report() const { std::cout << a << " " << b; }
    virtual ~error() throw() {}
};

class bad_hmean : public error{
public:
    explicit bad_hmean(const int x, const int y, const std::string & s = "hmean() : 매개변수 오류!") : error(x,y,s) {}
};

class bad_gmean : public error{
public:
    explicit bad_gmean(const int x, const int y, const std::string & s = "gmean() : 매개변수 오류!") : error(x,y,s) {}
};

#endif

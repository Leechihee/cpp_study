#ifndef EXCMEAN_H_
#define EXCMEAN_H_

#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error{
public:
    explicit bad_hmean(const char * s = "hmean() : 매개변수 오류!") : std::logic_error(s) {}
    ~bad_hmean() throw() {}
};

class bad_gmean : public std::logic_error{
public:
    explicit bad_gmean(const char * s = "gmean() : 매개변수 오류!") : std::logic_error(s) {}
    ~bad_gmean() throw() {}
};

#endif

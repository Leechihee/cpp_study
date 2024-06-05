#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd{
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd{
    char * pianist;
public:
    Classic(char * s1, char * s2, char * s3, int n, double x);
    Classic(const Classic & cl);
    Classic();
    ~Classic();
    void report() const;
    Classic & operator=(const Classic & cl);
};

#include "classic2.cpp"
#endif

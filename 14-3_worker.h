#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker{
    std::string fullname;
    long ld;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("No Name"), ld(0L) {}
    Worker(const std::string name, long n) : fullname(name), ld(n) {}
    virtual ~Worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};

class Waiter : virtual public Worker{
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string name, long n, int p) : Worker(name,n), panache(p) {}
    Waiter(const Worker & w, int p) : Worker(w), panache(p) {}
    void set();
    void show();
};

class Singer : virtual public Worker{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data();
    void Get();
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string name, long n, int v = other) : Worker(name,n), voice(v) {}
    Singer(const Worker & w,int v = other) : Worker(w), voice(v) {}
    void set();
    void show() const;
};

class SingingWaiter : public Waiter, public Singer{
protected:
    void Data();
    void Get();
public:
    SingingWaiter() : Worker(), Waiter(), Singer() {}
    SingingWaiter(const std::string name, long n, int p, int v = other) 
        : Worker(name,n), Waiter(name,n,p), Singer(name,n,v) {}
    SingingWaiter(const Worker & w,int p, int v = other)
        : Worker(w), Waiter(w,p), Singer(w,v) {}
    void set();
    void show() const;
};

#endif

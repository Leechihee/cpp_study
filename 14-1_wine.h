#ifndef WINE_H_
#define WINE_H_
#include <valarray>

//Pair Class
template<class T1,class T2>
class Pair{
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair();
};

template<class T1,class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}

template<class T1,class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

//Wine Class
class Wine{
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt> PairArray;
    char * label;
    int years;
    PairArray * wine_infor;
public:
    Wine();
    Wine(const char * la, int y, const int yt[], const int bot[]);
    Wine(const char * la, int y);
    ~Wine() {delete [] label; delete wine_infor;}
    void GetBottles();
    void Show() const;
    const char * Label() const {return label;}
    int sum() const {return wine_infor->second().sum();}
};

#endif

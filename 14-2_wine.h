#include <valarray>
#include <string>

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
class Wine : private std::string, private std::valarray<int>, private Pair<std::valarray<int>,std::valarray<int>>{
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt> PairArray;
    int years;
public:
    Wine() : std::string("NULL"), years(0), PairArray(ArrayInt(),ArrayInt()) {}
    Wine(const char * la,int y,int ys[],int bot[]);
    Wine(const char * la, int y);
    ~Wine() {}
    void GetBottles();
    void Show() const;
    const std::string & Label() const {return (const std::string &)(*this);}
    int sum() const {return PairArray::second().sum();}
};

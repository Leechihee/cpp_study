class Cd{
    char performers[50];
    char label[20];
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
    char pianist[80];
public:
    Classic(char * s1, char * s2, char * s3, int n, double x);
    Classic(const Classic & cl);
    Classic();
    void report() const;
    Classic & operator=(const Classic & cl);
};

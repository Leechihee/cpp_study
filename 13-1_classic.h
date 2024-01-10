class Cd{
    char perforemrs[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    virtual ~Cd();
    virtual void report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd{
    char name[80];
public:
    Classic(char * s1, char * s2, char * s3, int n, double x);
    Classic(const Classic & cl);
    void report() const;
    Classic & operator=(const Classic & cl);
};

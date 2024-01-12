#include <iostream>

class abcDMA{
    char * label;
    int rating;
public:
    abcDMA(const char * lb = "No Title", int r = 0);
    abcDMA(const abcDMA & aD);
    virtual ~abcDMA();
    virtual void View() const = 0;
    abcDMA & operator=(const abcDMA & aD);
};

class baseDMA : public abcDMA{
    
public:
    baseDMA(const char * lb = "No Title", int r = 0);
    baseDMA(const baseDMA & bD);
    ~baseDMA();
    void View() const;
    baseDMA & operator=(const baseDMA & bD);
};

class lacksDMA : public abcDMA{
    char * color;
public:
    lacksDMA(const char * lb = "No Title", int r = 0,const char * co = "NULL");
    lacksDMA(const lacksDMA & lD);
    ~lacksDMA();
    void View() const;
    lacksDMA & operator=(const lacksDMA & lD);
};

class hasDMA : public abcDMA{
    char * style;
public:
    hasDMA(const char * lb = "No Title", int r = 0,const char * st = "NULL");
    hasDMA(const hasDMA & hD);
    ~hasDMA();
    void View() const;
    hasDMA & operator=(const hasDMA & hD);
};

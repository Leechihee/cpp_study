#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

enum type{Employee,Manager,Fink,Highfink};

class abstr_emp{
    std::string fname;
    std::string lname;
    std::string job;
protected:
	void Data_to_file(std::ostream & os) const;
	void Data_to_Prog(std::istream & is);
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
    abstr_emp(const abstr_emp & e);
    virtual void ShowAll() const;
    virtual void SetAll();
	virtual void WriteAll(std::ostream & os) const;
	virtual void GetAll(std::istream & is);
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp{
public:
    employee();
    employee(const std::string & fn, const std::string & ln, const std::string & j);
    employee(const employee & e);
    void ShowAll() const;
    void SetAll();
	void WriteAll(std::ostream & os) const;
	void GetAll(std::istream & is);
};

class manager : virtual public abstr_emp{
    int inchargeof;
protected:
    int InChargeOF() const {return inchargeof;}
    int & InChargeOF() {return inchargeof;}
public:
    manager();
    manager(const std::string & fn, const std::string & ln, const std::string & j,int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    void ShowAll() const;
    void SetAll();
	void WriteAll(std::ostream & os) const;
	void GetAll(std::istream & is);
};

class fink : virtual public abstr_emp{
    std::string reportsto;
protected:
    const std::string ReportsTo() const {return reportsto;}
    std::string & ReportsTo() {return reportsto;}
public:
    fink();
    fink(const std::string & fn, const std::string & ln, const std::string & j,const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & f);
    void ShowAll() const;
    void SetAll();
	void WriteAll(std::ostream & os) const;
	void GetAll(std::istream & is);
};

class highfink : public manager, public fink{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
    highfink(const abstr_emp & e,const std::string rpo, int ico);
    highfink(const manager & m, const std::string rpo);
    highfink(const fink & f, int ico);
    highfink(const highfink & h);
    void ShowAll() const;
    void SetAll();
	void WriteAll(std::ostream & os) const;
	void GetAll(std::istream & is);
};

#include "emp.cpp"
#endif

#include "emp.h"
#include <iomanip>

namespace
{
    using namespace std;
}
//abstr_emp protected method
void abstr_emp::Data_to_file(ostream & os) const
{
	os << fname << " " << lname << endl;
	os << job << endl;
}

void abstr_emp::Data_to_Prog(std::istream & is)
{
	getline(is,fname,' ');
	getline(is,lname);
	getline(is,job);
}

//abstr_emp public method
abstr_emp::abstr_emp() : fname("None"), lname("None"), job("None") {}

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
    : fname(fn), lname(ln), job(j) {}
    
abstr_emp::abstr_emp(const abstr_emp & e) : fname(e.fname), lname(e.lname), job(e.job) {}

void abstr_emp::ShowAll() const
{
    cout << "이름 : " << fname + lname << endl;
    cout << "직업 : " << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "성을 입력하시오 : ";
    getline(cin,fname);
    cout << "이름을 입력하시오 : ";
    getline(cin,lname);
    cout << "직업을 입력하시오 : ";
    getline(cin,job);
}

void abstr_emp::WriteAll(ostream & os) const
{
	Data_to_file(os);
}

void abstr_emp::GetAll(istream & is)
{
	Data_to_Prog(is);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.fname << " " << e.lname << " is " << e.job;
    return os;
}

abstr_emp::~abstr_emp() {}

//employee public method
employee::employee() : abstr_emp() {}

employee::employee(const string & fn, const string & ln, const string & j)
    : abstr_emp(fn,ln,j) {}
    
employee::employee(const employee & e) : abstr_emp(e) {}
    
void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::WriteAll(std::ostream & os) const
{
	os << type::Employee << endl;
	abstr_emp::Data_to_file(os);
}

void employee::GetAll(istream & is)
{
	abstr_emp::Data_to_Prog(is);
}

//manager public method
manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const string & fn, const string & ln, const string & j,int ico)
    : abstr_emp(fn,ln,j), inchargeof(ico) {}
    
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "관리하는 사람 수 : " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "관리하는 사람 수를 입력하시오 : ";
    while(!(cin >> inchargeof).ignore(1,'\n'))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오 : ";
    }
}

void manager::WriteAll(std::ostream & os) const
{
	os << type::Manager << endl;
	abstr_emp::Data_to_file(os);
	os << inchargeof << endl;
}

void manager::GetAll(istream & is)
{
	abstr_emp::Data_to_Prog(is);
	(is >> inchargeof).ignore(1,'\n');
}

//fink public method
fink::fink() : abstr_emp(), reportsto("None") {}

fink::fink(const string & fn, const string & ln, const string & j,const string & rpo)
    : abstr_emp(fn,ln,j), reportsto(rpo) {}
    
fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & f) : abstr_emp(f), reportsto(f.reportsto) {}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "보고하는 상관 : " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "보고하는 상관의 성함을 입력하시오 : ";
    getline(cin, reportsto);
}

void fink::WriteAll(ostream & os) const
{
	os << type::Fink << endl;
	abstr_emp::Data_to_file(os);
	os << reportsto << endl;
}

void fink::GetAll(istream & is)
{
	abstr_emp::GetAll(is);
	getline(is,reportsto);
}

//highfink public method
highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico)
    : abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rpo) {}

highfink::highfink(const abstr_emp & e,const string rpo, int ico)
    : abstr_emp(e), manager(e,ico), fink(e,rpo) {}

highfink::highfink(const manager & m, const string rpo) : abstr_emp(m), manager(m), fink(m,rpo) {}

highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f,ico), fink(f) {}

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "관리하는 사람 수 : " << InChargeOF() << endl;
    cout << "보고하는 상관 : " << ReportsTo() << endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "관리하는 사람 수를 입력하시오 : ";
    cin >> InChargeOF();
    while(cin.get() != '\n')
        continue;
    cout << "보고하는 상관의 성함을 입력하시오 : ";
    getline(cin, ReportsTo());
}

void highfink::WriteAll(ostream & os) const
{
	os << type::Highfink << endl;
	abstr_emp::Data_to_file(os);
	os << InChargeOF() << endl;
	os << ReportsTo() << endl;
}

void highfink::GetAll(istream & is)
{
	abstr_emp::GetAll(is);
	(is >> InChargeOF()).ignore(1,'\n');
	getline(is,ReportsTo());
}

#include "Str.h"
#include <sstream>

namespace
{
	using namespace std;
}

void Store::operator() (const string & s) const
{
	int len = s.length();
	os.write((char*)&len,sizeof(size_t));
	os.write(s.data(), len);
}

void ShowStr(const string & s)
{
	cout << s << endl;
}

void GetStrs(istream & is, vector<string> & v)
{
	int len;
	while(is.read((char*)&len,sizeof(size_t)) && len > 0)
	{
		string t2;
		char t1[len+1];
		is.read((char*)&t1,len);
		t1[len] = '\0';
		t2 = t1;
		v.push_back(t2);
	}
}

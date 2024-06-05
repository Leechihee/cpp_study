#ifndef STR_H_
#define STR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace
{
	using namespace std;
}

class Store{
	ofstream & os;
public:
	explicit Store(ofstream & Os) : os(Os) {}
	void operator() (const string & s) const;
};

void ShowStr(const string & s);

void GetStrs(istream & is,vector<string> & v);

#include "Str.cpp"
#endif

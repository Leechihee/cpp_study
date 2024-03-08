#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>
#include <string>

namespace
{
	using namespace std;
}

class file{
	fstream f;
	string filename;
public:
	enum mode{INPUT,OUTPUT};
	explicit file(const string & filename, mode Mode);
	void chenge_mode(void);
	void fileRead(string & name, int & score);
	void fileWrite(const string & name, const int & score);
	void beg(void);
	~file() {f.close();}
private:
	mode m;
};

#endif

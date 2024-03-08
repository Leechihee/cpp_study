#include "File.h"
#include <cstdlib>
#include <exception>

file::file(const string & Filename,mode Mode) : filename(Filename)
{
	if(Mode == file::INPUT)
		f = fstream(filename, ios_base::in);
	if(Mode == file::OUTPUT)
		f = fstream(filename,ios_base::out | ios_base::trunc);
	m = (Mode == file::INPUT) ? file::INPUT : file::OUTPUT;
}

void file::chenge_mode(void)
{
	f.close();
	if(m == file::INPUT)
		f = fstream(filename,ios_base::out | ios_base::trunc);
	else
		f = fstream(filename,ios_base::in);
	m = (m == file::INPUT) ? file::OUTPUT : file::INPUT;
}

void file::fileRead(string & name, int & score)
{
	if(m == file::OUTPUT)
	{
		cout << "스트림모드가 적절하지 않습니다. 출력모드에서 입력모드로 전환합니다.\n";
		chenge_mode();
	}
	if(!f)
	{
		cout << "파일을 열 수 없습니다. 프로그램을 종료합니다.\n";
		exit(EXIT_FAILURE);
	}
	getline(f,name);
	(f>>score).ignore(1,'\n');
}

void file::fileWrite(const string & name, const int & score)
{
	if(m != file::OUTPUT)
	{
		cout << "스트림모드가 적절하지 않습니다. 출력모드에서 입력모드로 전환합니다.\n";
		chenge_mode();
	}
	f << name << endl << score << endl;
	cout << "성공적으로 파일에 출력하였습니다.\n";
}

void file::beg(void)
{
	f.seekp(ios_base::beg);
}

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	ifstream fin("test1.txt");
	if(!fin.is_open())
	{
		cout << "파일 오류!";
		return 1;
	}
	ifstream fin2("test2.txt");
	if(!fin2.is_open())
	{
		cout << "파일 오류!";
		return 2;
	}
	ofstream fout("result.txt");
	
	string temp;
	
	while(getline(fin,temp))
	{
		fout << temp << " ";
		getline(fin2,temp);
		fout << temp << endl;
	}
	cout << "END!" << endl;
	return 0;
}

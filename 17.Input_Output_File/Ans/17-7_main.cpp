#include <algorithm>
#include <cctype>
#include "../header/Str.h"

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	
	cout << "문자열들을 입력하십시오. (끝내려면 빈줄 입력) : ";
	while(getline(cin,temp) && temp.length() != 0)
	{
		vostr.push_back(temp);
		cout << "문자열들을 입력하십시오. (끝내려면 빈줄 입력) : ";
	}
	cout << "다음과 같이 입력하였습니다.\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);
	
	ofstream fout("strings.dat",ios_base::out | ios_base::binary);
	for_each(vostr.begin(),vostr.end(),Store(fout));
	fout.close();
	
	vector<string> vistr;
	ifstream fin("strings.dat",ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "입력을 위한 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin,vistr);
	cout << "\n파일로부터 읽은 문자열들은 다음과 같습니다.\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);
	
	cout << "종료!\n";
	return 0;
}

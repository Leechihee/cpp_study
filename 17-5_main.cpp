#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void out(const string & s)
{
	cout << s << " ";
}

vector<string> read_file(istream & is);

int main()
{
	ifstream fin("mat.dat");
	if(!fin.is_open())
	{
		cerr << "파일을 열 수 없습니다!\n";
		exit(EXIT_FAILURE);
	}
	cout << "메트 친구 파일 읽고 컨테이너에 입력 중\n";
	vector<string> mat(read_file(fin));
	cout << "\n입력 완료! 정보를 출력합니다!\n";
	for_each(mat.begin(),mat.end(),out);
	
	fin.clear();
	fin.close();
	
	fin.open("pat.dat");
	if(!fin.is_open())
	{
		cerr << "파일을 열 수 없습니다!\n";
		exit(EXIT_FAILURE);
	}
	cout << "\n페트 친구 파일 읽고 컨테이너에 입력 중\n";
	vector<string> pat(read_file(fin));
	cout << "입력 완료! 정보를 출력합니다!\n";
	for_each(pat.begin(),pat.end(),out);
	
	cout << "\n메트 컨테이너와 페트 컨테이너를 합병 중\n";
	vector<string> total(mat);
	total.insert(total.begin(),pat.begin(),pat.end());
	sort(total.begin(),total.end());
	unique(total.begin(),total.end());
	
	
	cout << "합병 완료! 파일에 정보를 출력합니다!\n";
	ofstream fout("matnpat.dat");
	int i = 0;
	for(int i = 0;i<total.size();i++)
		fout << total[i] << endl;
	cout << "파일 출력 완료!\n종료합니다!\n";
	
	fin.clear();
	fin.close();
	fout.clear();
	fout.close();
	return 0;
}

vector<string> read_file(istream & is)
{
	vector<string> temp;
	string temp_name;
	while(getline(is,temp_name))
		temp.push_back(temp_name);
	sort(temp.begin(),temp.end());
	return temp;
}

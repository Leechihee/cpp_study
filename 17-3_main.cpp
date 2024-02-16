#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
	using namespace std;
	if(argc < 3)
	{
		cerr << "사용법 : " << argv[0] << " copyFilename targetFilename\n";
		exit(EXIT_FAILURE);
	}
	
	ifstream fin(argv[1]);
	if(!fin.is_open())
	{
		cerr << "파일을 열 수 없습니다!\n";
		exit(EXIT_FAILURE);
	}
	ofstream fout(argv[2]);
	
	char temp;
	while(fin.get(temp))
		fout << temp;
	
	cout << argv[1] << "파일의 내용을 " << argv[2] << "파일로 복사완료!\n";
	fin.clear();
	fin.close();
	fout.close();
	
	cout << argv[2] << "파일 내용을 출력합니다.\n";
	ifstream fin2(argv[2]);
	while(fin2.get(temp))
		cout << temp;
	cout << endl;
	cout << "종료!\n";
	return 0;
}

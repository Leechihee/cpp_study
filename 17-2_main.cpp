#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc, char * argv[])
{
	using namespace std;
	if(argc == 1)
	{
		cerr << "사용법 : " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}
	
	ofstream fout;
	for(int file = 1; file < argc; file++)
	{
		fout.open(argv[file]);
		if(!fout.is_open())
		{
			cerr << argv[file] << " 파일을 열 수 없습니다.\n";
			fout.clear();
			continue;
		}
		cout << "파일에 출력할 내용을 입력하시오. : ";
		char output;
		while(cin.get(output) && output != '\n')
		{
			fout << output;
			cout << output;
		}
		cout << "을 " << argv[file] << "파일에 출력했습니다.\n";
		fout.clear();
		fout.close();
	}
	cout << "종료!";
	return 0;
}

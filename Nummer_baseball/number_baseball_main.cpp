#include <iostream>
#include <ctime>
#include "number_baseball.h"
#include "File.h"

using namespace std;

void delay(int t);

int main()
{
	cout << "최근 성공 전적을 읽어옵니다.\n";
	file File("score.dat",file::INPUT);
	string name;
	int score;
	File.fileRead(name,score);
	cout << name << " " << score << endl;
	number_baseball player;
	delay(1);
	if(player.playball())
	{
		cout << "최근 성공 전적을 기록합니다.\n이름을 입력하시오 : ";
		cin.ignore(1,'\n');
		getline(cin,name);
		File.chenge_mode();
		File.fileWrite(name,player.ret_score());
	}
	cout << "종료!";
	return 0;
}

void delay(int t)
{
	clock_t start = clock() + t * CLOCKS_PER_SEC;
	while(clock()< start) {}
}

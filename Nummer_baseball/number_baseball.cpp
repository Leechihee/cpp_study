#include "number_baseball.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace { using namespace std;}

number_baseball::number_baseball(void)
{
	srand(time(0));
	int erorr = 0;
	do
	{
		num[0] = rand() % 9 + 1;
		num[1] = rand() % 10;
		num[2] = rand() % 10;
		if(num[0] == num[1] || num[0] == num[2])
			erorr++;
		else if(num[1] == num[0] || num[1] == num[2])
			erorr++;
		else if(num[2] == num[0] || num[2] == num[1])
			erorr++;
	}while(erorr != 0);
	cout << "숫자야구 세팅완료. 잠시후 숫자야구를 실시합니다.\n";
}

bool number_baseball::Catch(void) const
{
	cout << "세자리 숫자를 입력하시오 : ";
	int ans,temp[3];
	while(!(cin >> ans) || (ans < 99 || ans > 999))
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "입력오류거나 세자리 숫자가 아닙니다.\n다시 입력하시오 : ";
	}
	
	for(int index = 2;index>-1;index--)
	{
		temp[index] = ans%10;
		ans /= 10;
	}
	
	int strike=0, ball=0, out=0;
	
	if(temp[0] == num[0]) 
		strike++;
	else if(temp[0] == num[1] || temp[0] == num[2]) 
		ball++;
	else 
		out++;
	
	if(temp[1] == num[1]) 
		strike++;
	else if(temp[1] == num[0] || temp[1] == num[2]) 
		ball++;
	else 
		out++;
	
	if(temp[2] == num[2]) 
		strike++;
	else if(temp[2] == num[1] || temp[2] == num[0]) 
		ball++;
	else 
		out++;
	
	if(strike == 3)
	{
		cout << strike << "Strike!!" << endl;
		return true;
	}else
	{
		cout << strike << "Strike, " << ball << "Ball, " << out << "Out.\n";
		return false;
	}
}

bool number_baseball::playball(void)
{
	cout << "숫자야구를 시작합니다. 숫자 자릿수는 세자리이며 기회는 총 10번이고 각 자리숫자의 중복은 없습니다.\n";
	while(!Catch())
	{
		count--;
		if(count == -1) break;
		cout << count << "번 남았습니다.\n";
	}
	if(count < 0)
	{
		cout << "기회를 다 소진하여 패배하였습니다.\n";
		cout << "정답은 " << ret_num() << "이였습니다.\n";
		return false;
	}
	cout << "정답입니다! 남은 기회는 총 " << count << "번이였습니다.\n";
	score = count * 10;
	return true;
}

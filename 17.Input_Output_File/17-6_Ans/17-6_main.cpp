#include <fstream>
#include <cctype>
#include <iomanip>
#include <cctype>
#include "emp.h"
const int LIM = 10;

using namespace std;

bool choice_job(ostream & os);
int reading_file(istream & is, abstr_emp * em[]);

int main()
{
	ifstream fin("employee.dat",ios_base::in);
	ofstream fout("employee.dat",ios_base::out | ios_base::app);
	if(!fin.is_open())
	{
		int Fcount = 0;
		cout << "최초 실행입니다. employee.dat 파일을 생성하고 최초정보를 입력합니다.\n";
		while(choice_job(fout) && Fcount < LIM) Fcount++;
		cout << "프로그램을 다시 시작하시오.\n";
		fout.close();
		exit(EXIT_FAILURE);
	}
	abstr_emp * emp_arr[LIM];
	int count = reading_file(fin,emp_arr);
	for(int i = 0;i<count;i++)
	{
		emp_arr[i]->ShowAll();
		cout << endl;
	}
	fin.clear();
	fin.close();
	
	if(count < LIM)
	{
		cout << "추가할 내용을 입력하시오.\n";
		while(!choice_job(fout))
		{
			cout << "입력오류! 다시 입력하시오.\n";
		}
	}
	else
		cout << "한도를 초과했습니다.\n";
	
	fout.clear();
	fout.close();
	
	fin.open("employee.dat", ios_base::in);
	cout << "파일을 읽어 스크린에 출력합니다.\n";
	count = reading_file(fin,emp_arr);
	for(int i = 0;i<count;i++)
	{
		emp_arr[i]->ShowAll();
		cout << endl;
	}
	cout << "종료!\n";
	fin.clear();
	fin.close();
	return 0;
}

bool choice_job(ostream & os)
{
	abstr_emp * temp;
	char ans;
	cout << left << setw(15) << "A.Employee" << "B.Manager\n"
		<< setw(15) << "C.Fink" << "D.Highfink\n" << "Q.Quit\n";
	cout << "선택지를 선택하시오 : ";
	cin.get(ans).ignore(1,'\n');
	switch(tolower(ans))
	{
		case 'a':
			temp = new employee;
			break;
		case 'b':
			temp = new manager;
			break;
		case 'c':
			temp = new fink;
			break;
		case 'd':
			temp = new highfink;
			break;
		case 'q':
			cout << "입력을 종료합니다\n";
			return true;
		default:
			cout << "입력오류! 입력을 종료합니다.\n";
			return false;
	}
	temp->SetAll();
	temp->ShowAll();
	cout << "입력하신 정보가 맞습니까? (y/n) : ";
	cin.get(ans).ignore(1,'\n');
	while(tolower(ans) != 'y')
	{
		cout << "다시 입력하시오.\n";
		temp->SetAll();
		temp->ShowAll();
		cout << "입력하신 정보가 맞습니까? (y/n) : ";
		cin.get(ans).ignore(1,'\n');
	}
	cout << "입력한 정보를 employee.dat 파일에 출력합니다.\n";
	temp->WriteAll(os);
	delete temp;
	return true;
}

int reading_file(istream & is, abstr_emp * em[])
{
	int classtype;
	int i = 0;
	while((is>>classtype).ignore(1,'\n'))
	{
		switch (classtype)
		{
			case 0:
				em[i] = new employee;
				break;
			case 1:
				em[i] = new manager;
				break;
			case 2:
				em[i] = new fink;
				break;
			case 3:
				em[i] = new highfink;
				break;
		}
		em[i]->GetAll(is);
		i++;
	}
	cout << "모든 내용을 읽었습니다.\n";
	return i;
}

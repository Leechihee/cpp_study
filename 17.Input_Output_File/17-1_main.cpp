#include <iostream>

int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "문자열을 입력하시오.(끝내려면 $) : ";
	while(cin.get(ch) && ch != '$')
		count++;
	cout << count << "개의 문자를 읽었고 입력 스트림엔 " << ch << "가 남아있습니다.";
	return 0;
}

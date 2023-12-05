#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("test.txt");
    char ch;
    int ct = 0;
    while(!(inFile.eof()))
    {
        inFile >> ch;
        if(inFile.good())
            ct++;
    }
    cout << "파일 안에 있는 문자들의 수는 " << ct << "개이다.";
    inFile.close();
    return 0;
}

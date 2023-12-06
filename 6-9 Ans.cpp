#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct donation
{
    string first_name;
    string last_name;
    double money;
};

int main()
{
    ifstream inFile;
    inFile.open("donation.txt");
    int num, temp = 0;
    
    inFile >> num;
    donation * pd = new donation[num];
    for(int i = 0;i<num;i++)
    {
        inFile >> pd[i].first_name;
        inFile >> pd[i].last_name;
        inFile >> pd[i].money;
        temp += pd[i].money;
    }
    
    temp = temp/num;
    
    cout << "고액 기부자\n";
    for(int i = 0;i<num;i++)
    {
        if(temp < pd[i].money)
            cout << pd[i].first_name << " " << pd[i].last_name << endl;
    }
    
    cout << "소액 기부자\n";
    for(int i = 0;i<num;i++)
    {
        if(temp > pd[i].money)
            cout << pd[i].first_name << " " << pd[i].last_name << endl;
    }
    inFile.close();
    delete [] pd;
    return 0;
}

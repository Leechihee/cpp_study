#include <iostream>
#include <array>

using namespace std;


const int size = 4;
const char *seasons[size] = {"Spring","Summer","Fail","Winter"};

void fill(array<double, size> *sea);

int main()
{
    array<double, size> seasons_cost;
    fill(&seasons_cost);
    return 0;
}

void fill(array<double, size> *sea)
{
    for(int i=0;i<size;i++)
    {
        cout << seasons[i] << "에 소요되는 비용 : ";
        cin >> *(sea+i);
    }
}

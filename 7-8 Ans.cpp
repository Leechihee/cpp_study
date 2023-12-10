#include <iostream>
#include <array> // a인 경우

using namespace std;


const int size = 4;
const char *seasons[size] = {"Spring","Summer","Fail","Winter"};

// b인 경우
struct seasons_costs
    {
        double costs[size];
    };
    
void fill(seasons_costs *);
void show(seasons_costs);

int main()
{
    seasons_costs cost;
    fill(&cost);
    show(cost);
    return 0;
}

void fill(seasons_costs *addrass)
{
    for(int i=0;i<size;i++)
    {
        cout << seasons[i] << "에 소요되는 비용 : ";
        cin >> *(addrass->costs+i);
    }
}

void show(seasons_costs addrass)
{
    double total = 0.0;
    cout << endl << "계절별 비용\n";
    for(int i = 0;i<size;i++)
        {
            cout << seasons[i] << "에 드는 비용은 " << addrass.costs[i] << "$이다\n";
            total += addrass.costs[i];
        }
    cout << "총 비용은 " << total << "$이다.";
}


// a인 경우
/*
void fill(array<double, size> *);
void show(array<double, size>);

int main()
{
    array<double, size> seasons_cost;
    fill(&seasons_cost);
    show(seasons_cost);
    return 0;
}

void fill(array<double, size> *sea)
{
    for(int i=0;i<size;i++)
    {
        cout << seasons[i] << "에 소요되는 비용 : ";
        cin >> (*sea)[i];
    }
}

void show(array<double, size> sea)
{
    double total = 0.0;
    cout << endl << "계절별 비용\n";
    for(int i = 0;i<size;i++)
        {
            cout << seasons[i] << "에 드는 비용은 " << sea[i] << "$이다\n";
            total += sea[i];
        }
    cout << "총 비용은 " << total << "$이다.";
}
*/

#include <iostream>

using namespace std;

const int max = 10;

double *fill_array(double *, int);
void show_array(const double *, double*);
void revalue(double *,double *,double);

int main()
{
    double properties[10];
    double *count_adrass = fill_array(properties,10);
    show_array(properties,count_adrass);
    if(!(*properties))
    {
        cout << "입력한 부동산의 정보가 없습니다.\n";
        return 1;
    }
    double factor;
    cout << "재평가율을 입력하시오 : ";
    while(!(cin>>factor))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "입력오류! 수치를 다시 입력하시오. : ";
    }
    revalue(properties,count_adrass,factor);
    show_array(properties,count_adrass);
    cout << "프로그램을 종료합니다.";
    return 0;
}

double* fill_array(double * proArray, int count)
{
    int i;
    for(i= 0;i<count;i++)
    {
        cout << i+1 << "번 부동산의 가격 : $";
        if(!(cin>>*(proArray+i)))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "입력불량! 입력과정을 종료\n";
            break;
        }
    }
    return proArray+i+1;
}

void show_array(const double *proArray,double* adrass)
{
    const double* start;
    double* end;
    int i = 1;
    for(start = proArray, end = adrass;start<end-1;start++,i++)
    {
        cout << i << "번 부동산가격 : $" << *start << endl;
    }
}

void revalue(double *proArray,double* adrass, double rev)
{
    double* start;
    double* end;
    int i;
    for(start = proArray,end = adrass,i=0;start<end-1;start++,i++)
        *start = *(start)*rev;
}

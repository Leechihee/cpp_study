#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
const int MIN_PER_HR = 60;

bool newcustmer(double x);

class custmer{
    long arrive;
    int processtime;
public:
    explicit custmer() : arrive(0), processtime(0) {}
    void set(long when) { processtime = std::rand() % 3 +1; arrive = when; }
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef custmer item;

int main()
{
    using namespace std;
    srand(time(0));
    cout << "사례 연구 : 히서 은행의 ATM\n";
    cout << "큐의 최대 길이를 입력하시오 : ";
    int Size;
    cin >> Size;
    queue<item> qu;
    
    cout << "시뮬레이션 시간 수를 입력하시오 : ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    
    cout << "시간당 평균 고객 수를 입력하시오 : ";
    double perhours;
    cin >> perhours;
    double min_per_cust = MIN_PER_HR / perhours;
    
    item temp;
    long turnaways = 0;
    long custmers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;
    
    for(int cycle = 0;cycle < cyclelimit;cycle++)
    {
        if(newcustmer(min_per_cust))
        {
            if(qu.size() == Size)
                turnaways++;
            else
            {
                custmers++;
                temp.set(cycle);
                qu.push(temp);
            }
            if(wait_time <= 0 && !qu.empty())
            {
                temp = qu.back();
                qu.pop();
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time > 0)
                wait_time--;
            sum_line += qu.size();
        }
    }
    
    if(custmers > 0)
    {
        cout << " 큐에 줄을 선 고객 수 : " << custmers << endl;
        cout << "거래를 처리한 고객 수 : " << served << endl;
        cout << " 발길을 골린 고객 수 : " << turnaways << endl;
        cout << "       평균 큐의 길이 : ";
        cout << (double)sum_line / cyclelimit << endl;
        cout << "       평균 대기 시간 : ";
        cout << (double) line_wait / served << "분\n";
    }
    else
        cout << "고객이 한명도 없습니다!\n";
    cout << "완료!";
    
    return 0;
}

bool newcustmer(double x)
{
    return ( std::rand() * x / RAND_MAX < 1);
}

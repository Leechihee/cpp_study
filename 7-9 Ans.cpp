#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);
int main()
{
    cout << "학급의 학생 수를 입력하십시오 : ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        continue;
    
    student * ptr_stu = new student [class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i=0;i<class_size;i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
        cout << endl;
    }
    display3(ptr_stu,class_size);
    delete [] ptr_stu;
    cout << "프로그램을 종료합니다.";
    return 0;
}

int getinfo(student pa[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << "학생의 이름을 입력하시오. (빈칸입력시 입력종료) : ";
        cin.getline(pa[i].fullname,SLEN);
            if(pa[i].fullname[0] == '\0')
            {
                cout << "입력오류! 입력을 종료합니다!\n";
                break;
            }
        cout << "학생의 취미를 입력하시오 : ";
        cin.getline(pa[i].hobby,SLEN);
            while(pa[i].hobby[0] == '\0')
            {
                cout << "입력오류! 취미를 입력하시오. : ";
                cin.getline(pa[i].hobby,SLEN);
            }
        cout << "학생의 점수를 입력하시오 : ";
        while(!(cin>>pa[i].ooplevel))
            {
                cin.clear();
                while(cin.get() != '\n')
                    continue;
                cout << "입력오류! 점수를 입력하시오. : ";
            }
        cin.get();
    }
    return i;
}

void display1(student st)
{
    cout << "Display1 | 학생 이름 : " << st.fullname << endl;
    cout << "Display1 | 학생 취미 : " << st.hobby << endl;
    cout << "Display1 | 학생 성적 : " << st.ooplevel << endl;
}
void display2(const student *ps)
{
    cout << "Display2 | 학생 이름 : " << ps->fullname << endl;
    cout << "Display2 | 학생 취미 : " << ps->hobby << endl;
    cout << "Display2 | 학생 성적 : " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    for(int i= 0;i<n;i++)
    {
        cout << "Display3 | 학생 이름 : " << pa[i].fullname << endl;
        cout << "Display3 | 학생 취미 : " << pa[i].hobby << endl;
        cout << "Display3 | 학생 성적 : " << pa[i].ooplevel << endl;
    }
}

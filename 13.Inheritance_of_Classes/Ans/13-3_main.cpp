#include "../header/dma.h"

namespace
{
    using namespace std;
}

int main()
{
    abcDMA * paD[3];
    char in_label[80];
    int in_rating, ans;
    char in_etc[50];
    for(int i = 0;i<3;i++)
    {
        cout << "상표를 입력하시오. : ";
        cin.getline(in_label,80);
        cout << "등급을 입력하시오. : ";
        while(!(cin >> in_rating))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오. : ";
        }
        cout << "객체를 선택하시오.\n" << "1. baseDMA / 2. lacksDMA / 3. hasDMA \n";
        while(!(cin >> ans))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오. : ";
        }
        while(cin.get() != '\n')
            continue;
        if(ans == 1)
        {
            cout << "baseDMA 객체를 선택하셨습니다.\n";
            paD[i] = new baseDMA(in_label,in_rating);
        }
        else if(ans == 2)
        {
            cout << "lacksDMA 객체를 선택하셨습니다.\n색상을 입력하시오. : ";
            cin.getline(in_etc,50);
            paD[i] = new lacksDMA(in_label,in_rating,in_etc);
        }
        else if(ans == 3)
        {
            cout << "hasDMA 객체를 선택하셨습니다.\n스타일을 입력하시오. : ";
            cin.getline(in_etc,50);
            paD[i] = new hasDMA(in_label,in_rating,in_etc);
        }
        else
        {
            cout << "입력오류! baseDMA 객체로 자동 선택됩니다.\n";
            paD[i] = new baseDMA(in_label,in_rating);
        }
    }
    for(int i = 0;i<3;i++)
    {    
        paD[i]->View();
        cout << endl;
    }
    cout << "새로운 abcDMA 포인터배열 npaD을 선언하고 paD 포인터배열 값을 대입 및 출력한다.\n";
    abcDMA * npaD[3];
    for(int i = 0;i<3;i++)
        npaD[i] = paD[i];
    for(int i = 0;i<3;i++)
    {    
        npaD[i]->View();
        cout << endl;
    }
    for(int i = 0;i<3;i++)
    {
        delete paD[i];
        delete npaD[i];
    }
    return 0;
}

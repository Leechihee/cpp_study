#include <iostream>
using namespace std;
#include "classic.h"

void bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Phillps",2,57.17);
    Cd * pcd = &c1;
    
    cout << "객체를 직접 사용한다:\n\n";
    c1.report();
    c2.report();
    
    cout << "\n객체를 지시하는 Cd * 포인터를 사용한다\n\n";
    pcd->report();
    pcd = &c2;
    pcd->report();
    
    cout << "\nCd 참조 매개변수를 사용하여 함수를 호출한다:\n\n";
    bravo(c1);
    bravo(c2);
    
    cout << "\n대입을 테스트한다:\n\n";
    Classic copy;
    copy = c2;
    copy.report();
    
    return 0;
}

void bravo(const Cd & disk)
{
    disk.report();
}

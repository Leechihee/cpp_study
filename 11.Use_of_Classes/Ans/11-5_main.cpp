#include "../header/stonewt1.h"

int main()
{
    using namespace std;
    Stonewt s1(10,0.5);
    Stonewt s2(9.5);
    Stonewt s3(10);
    Stonewt s4;
    
    cout << "s1 + s4 = " << s1+s4 << endl;
    cout << "s3 - s2 = " << s3-s2 << endl;
    cout << "s2 * s3 = " << s2*s3 << endl;
    return 0;
}

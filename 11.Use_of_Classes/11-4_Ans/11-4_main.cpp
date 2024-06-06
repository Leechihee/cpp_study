#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time lee(3,35);
    Time kim(2,48);
    
    cout << "lee와 kim:\n";
    cout << lee << "; " << kim << endl;
    cout << "lee + kim = ";
    cout << lee + kim << endl;
    cout << "lee - kim = ";
    cout << lee - kim << endl;
    cout << "lee * 1.5 = ";
    cout << lee * 1.5 << endl;
    cout << "1.5 * kim = ";
    cout << 1.5 * kim << endl;
    return 0;
}

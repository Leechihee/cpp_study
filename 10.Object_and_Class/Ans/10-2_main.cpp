#include <iostream>
#include "../header/person.h"

namespace
{
    using std::cout;
    using std::endl;
}

int main()
{
    person one;
    person two("Smythecraft");
    person three("Dimwiddy","Sam");
    one.Show();
    cout << endl;
    one.FormalShow();
    two.Show();
    cout << endl;
    two.FormalShow();
    three.Show();
    cout << endl;
    three.FormalShow();
    return 0;
}

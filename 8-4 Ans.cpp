#include <iostream>

using namespace std;
#include <cstring>
struct stringy
{
    char * str;
    int ct;
};
void set(stringy &,const char *);
void show(const stringy &stri ,int n = 1)
{
    for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<stri.ct;j++)
                cout << stri.str[j];
            cout << endl;
        }
}

void show(const char *str ,int n = 1)
{
    for(int i = 0;i<n;i++)
        cout << str << endl;
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing,3);
    show("Done!");
    return 0;
}

void set(stringy &stri, const char *copy)
{
    char *temp = new char[strlen(copy)+1];
    stri.str = temp;
    strcpy(temp,copy);
    stri.ct = strlen(temp);
}

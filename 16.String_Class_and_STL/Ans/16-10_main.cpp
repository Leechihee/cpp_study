#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cctype>

using namespace std;

struct Review{
    string title;
    int rating;
    int price;
};

bool operator<(const Review & r1, const Review &r2);
bool rating_then(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2);
bool price_then(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2);
bool fill(shared_ptr<Review> & p);
void out(const shared_ptr<Review> p);

int main()
{
    vector<shared_ptr<Review>> books, temps;
    shared_ptr<Review> temp;
    char ans;
    while(fill(temp))
        books.push_back(temp);
    while(books.size() > 0 && ans != 'q')
    {
        temps = books;
        cout << "A.입력순\tB.문자순\tC.등급순\nD.가격 내림차순\tE.가격 올림차순\tQ.끝내기\n";
        cout << "표기 방법를 입력하시오 : ";
        cin >> ans;
        cout << "\t등급 / 제목 / 가격\n";
        switch(tolower(ans))
        {
            case 'a':
                for_each(books.begin(),books.end(),out);
                continue;
            case 'b':
                sort(temps.begin(),temps.end());
                for_each(temps.begin(),temps.end(),out);
                continue;
            case 'c':
                sort(temps.begin(),temps.end(),rating_then);
                for_each(temps.begin(),temps.end(),out);
                continue;
            case 'd':
                sort(temps.rbegin(),temps.rend(),price_then);
                for_each(temps.begin(),temps.end(),out);
                continue;
            case 'e':
                sort(temps.begin(),temps.end(),price_then);
                for_each(temps.begin(),temps.end(),out);
                continue;
            case 'q':
                ans = 'q';
                break;
            default:
                cout << "선택지에 없는 선택입니다.\n";
        }
    }
    cout << "종료!";
    return 0;
}

bool fill(shared_ptr<Review> & p)
{
    shared_ptr<Review> temp(new Review);
    cout << "책 제목을 입력하시오 (끝내려면 quit) : ";
    if(getline(cin,temp->title) && temp->title == "quit")
        return false;
    cout << "책 등급을 입력하시오 : ";
    while(!(cin>>temp->rating))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오 : ";
    }
    cout << "책 가격을 입력하시오 : ";
    while(!(cin >> temp->price))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오 : ";
    }
    cin.get();
    p = temp;
    return true;
}

void out(const shared_ptr<Review> p)
{
    cout << p->rating << "\t" << p->title << "\t" << p->price << endl;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2)
{
    if(r1->title < r2->title)
        return true;
    else if(r1->rating < r2->rating)
        return true;
    else if(r1->price < r2->price)
        return true;
    else
        return false;
}

bool rating_then(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2)
{
    if(r1->rating < r2->rating)
        return true;
    else 
        return false;
}

bool price_then(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2)
{
    if(r1->price < r2->price)
        return true;
    else
        return false;
}

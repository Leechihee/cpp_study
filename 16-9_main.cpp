#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> vi0(10000000,rand() % 4);
    vector<int> vi(vi0);
    list<int> li(vi0.begin(),vi0.end());
    clock_t v_start = clock();
    sort(vi.begin(),vi.end());
    clock_t v_end = clock();
    cout << "STL sort()로 vi를 정렬하는데 걸린 시간은 : " << (double)(v_end - v_start)/ CLOCKS_PER_SEC << endl;
    clock_t l_start = clock();
    li.sort();
    clock_t l_end = clock();
    cout << "list 메서드 sort()로 li를 정렬하는데 걸린 시간은 : " << (double)(l_end - l_start)/ CLOCKS_PER_SEC << endl;
    copy(vi0.begin(),vi0.end(),li.begin());
    v_start = clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(),vi.end());
    v_end = clock();
    cout << "STL sort()로 새로운 vi를 정렬하는데 걸린 시간은 : " << (double)(v_end - v_start)/ CLOCKS_PER_SEC << endl;
    return 0;
}

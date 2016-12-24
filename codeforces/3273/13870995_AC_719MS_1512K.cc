
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
#define MAX_N 100000 + 16
int N, M;
ULL money[MAX_N];
 
bool C(ULL d)
{
    int periods  = 1;
    ULL expenses = 0;
    for (int i = 0; i < N; ++i)
    {
        expenses += money[i];
        if (expenses > d)
        {
            expenses = money[i];
            ++periods;
        }
    }
    if (periods > M)
    {
        return true;
    }
    return false;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> money[i];
    }
    ULL lb = *max_element(money, money + N), ub = accumulate(money, money + N, 0);
    while (lb < ub)
    {
        ULL mid = (lb + ub) / 2;
        if (C(mid))
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid;
        }
    }
    cout << lb << endl;
    return 0;
}
///////////////////////////End Sub//////////////////////////////////
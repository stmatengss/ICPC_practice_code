////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 18:40:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1124
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

ll factor(ll a,ll num)
{
    ll res=0;
    while(num)
    {
        num/=a;
        res+=num;
    }
    return res;
}

int main()
{
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<min(factor(2,n),factor(5,n))<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 16:29:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1719
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1752KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;

bool pending(ll n)
{
    if(n==0)return false;
    n++;
    while(n%2==0)n/=2;
    while(n%3==0)n/=3;
    if(n==1)return true;
    return false;
}

int main()
{
    ll n;
    while(cin>>n)
    {
        cout<<(pending(n)?"YES!":"NO!")<<endl;
    }
    return 0;
}
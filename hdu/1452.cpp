////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 18:58:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1452
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1796KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;

const ll mod=29;

ll quickmod(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n=n>>1;
    }
    return res;
}

int main()
{
    ll n;
    while(cin>>n,n)
    cout<<((quickmod(2,2*n+1)-1)%mod*(quickmod(3,n+1)-1)*15%mod*(quickmod(167,n+1)-1)*18%mod)<<endl;
    return 0;
}

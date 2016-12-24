////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 13:41:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1576
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1796KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;
const ll mod=9973;

ll quick_mod(ll a,ll n)
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
    int t;
    ll n,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        cout<<(n*quick_mod(b,9971ll)%mod)<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
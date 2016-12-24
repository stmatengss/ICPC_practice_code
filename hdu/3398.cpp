////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-25 16:22:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3398
////Problem Title: 
////Run result: Accept
////Run time:826MS
////Run memory:18424KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

typedef long long ll;
long long prime[400007];
long long isprime[2000007];
const long long mod=20100501;
int n,m;

void table()
{
    int counter=0;
    int i,j;
    isprime[1]=1;
    for(i=2;i<=2000004;i++)
    {
        if(isprime[i]==0)
        {
            prime[counter++]=i;
            for(j=2*i;j<=2000004;j+=i)
                isprime[j]=1;
        }
    }
}

ll powmod(ll a,ll nn)
{
    ll res=1;
    while(nn)
    {
        if(nn&1)res=(res*a)%mod;
        a=(a*a)%mod;
        nn=nn>>1;
    }
    return res;
}

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

ll cal(int a,int b)
{
    ll num=0;
    ll res=(a-b+1);
    for(int i=0;prime[i]<=a+b;i++)
    {
        num=factor(prime[i],(a+b))-factor(prime[i],(b))-factor(prime[i],(a+1));
        if(num>=0)res=res*powmod(prime[i],num)%mod;
        else
            res=res/powmod(prime[i],-num)%mod;
    }
    return res;
}

int main()
{
    int t;
    table();
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%I64d\n",cal(n,m));
    }
    return 0;
}

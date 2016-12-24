#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
ll prime[200007];
ll sum[2000007];
ll isprime[1000007];
int n,m;

void table()
{
    int counter=0;
    int i,j;
    isprime[1]=1;
    for(i=2;i<=1000004;i++)
    {
        if(isprime[i]==0)
        {
            prime[counter++]=i;
            for(j=2*i;j<=1000004;j+=i)
                isprime[j]=1;
        }
    }
}

ll powmod(ll a,ll nn)
{
    ll res=1;
    while(nn)
    {
        if(nn&1)res=(res*a)%10;
        a=(a*a)%10;
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

void cal()
{
    int res,i,j;
    for(i=0;prime[i]<=n;i++)
    {
        sum[i]+=factor(prime[i],n)-factor(prime[i],n-m);
    }
    for(i=0;prime[i]<=m;i++)
    {
        sum[i]-=factor(prime[i],m);
    }
    if(sum[0]>sum[2])
    {
        res=powmod(2,sum[0]-sum[2]);
    }
    else
    {
        res=powmod(5,sum[2]-sum[0]);
    }
    for(i=1;prime[i]<=n;i++)
    {
        if(prime[i]!=5)
        {
            res=(res*powmod(prime[i],sum[i]))%10;
        }
    }
    cout<<res<<endl;
}

int main()
{
    table();
    while(cin>>n>>m)
    {
        memset(sum,0,sizeof(sum));
        cal();
    }
//    cout << "Hello world!" << endl;
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 11:05:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1431
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1808KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll>rec;
ll tab[14]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

ll pow_mod(ll a,ll d,ll n)
{
    ll res=1;
    while(d)
    {
        if(d&1)res=(res*a)%n;
        a=(a*a)%n;
        d=d>>1;
    }
    return res;
}

bool test(int n,int a,int d)
{
    if(n==2)return true;
    if(n==a)return true;
    if((n&1)==0)return false;
    while(!(d&1))d=d>>1;
    int t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(ll)t*t%n;
        d=d<<1;
    }
    return (t==n-1||(d&1)==1);
}

bool isprime(int n)
{
    if(n<2)return false;
    int a[]={2,3,61};
    for(int i=0;i<=2;i++)if(!test(n,a[i],n-1))return false;
    return true;
}

void dfs(ll n,int len)
{
    if(n%10!=0&&isprime(n))
        rec.push_back(n);
    if(len>=7)
    {
        return;
    }
    for(int i=0;i<=9;i++)
    {
        dfs(i*tab[len+1]+n*10+i,len+2);
    }
    return;
}

int main()
{
    ll a,b;
    int i,j;
    vector<ll>::iterator be,en,k;
    for(i=0;i<=9;i++)
    {
        dfs(i,1);
        dfs(i*10+i,2);
    }
    sort(rec.begin(),rec.end());
    while(cin>>a>>b)
    {
        be=lower_bound(rec.begin(),rec.end(),a);
        en=upper_bound(rec.begin(),rec.end(),b);
        for(k=be;k!=en;++k)
            cout<<(*k)<<endl;
        cout<<endl;
    }

//    for(i=0;i<40;i++)
//        cout<<rec[i]<<endl;
//    for(i=rec.size()-1;i>rec.size()-20;i--)
//        cout<<rec[i]<<endl;
    return 0;
}

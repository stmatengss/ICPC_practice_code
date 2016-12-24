////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-06 12:47:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1573
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1780KB
//////////////////System Comment End//////////////////
/**中国剩余定理（不互质）*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll Mod;
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d = Extend_Euclid(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
ll inv(ll a, ll n) //a在模n乘法下的逆元，没有则返回-1
{
    ll x,y;
    ll t = Extend_Euclid(a,n,x,y);
    if(t != 1)
        return -1;
    return (x%n+n)%n;
}
bool merge(ll a1, ll n1, ll a2, ll n2, ll& a3, ll& n3) //将两个方程合并为一个
{
    ll d = gcd(n1,n2);
    ll c = a2-a1;
    if(c%d)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}
ll China_Reminder2(int len, ll* a, ll* n) //求模线性方程组x=ai(mod ni),ni可以不互质
{
    ll a1=a[0],n1=n[0];
    ll a2,n2;
    for(int i = 1; i < len; i++)
    {
        ll aa,nn;
        a2 = a[i],n2=n[i];
        if(!merge(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return a1;
//    return (a1%n1+n1)%n1;
}
ll a[1000],b[1000];
int main()
{
    int i;
    ll k,n;
    ll a1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i = 0; i < k; i++)
            cin>>a[i];
        for(i = 0; i < k; i++)
            cin>>b[i];
        a1=China_Reminder2(k,b,a);
        if(a1==-1||n<a1)
            cout<<"0"<<endl;
        else
            cout<<((n-a1)/Mod+1-(a1==0?1:0))<<endl;
    }
    return 0;
}

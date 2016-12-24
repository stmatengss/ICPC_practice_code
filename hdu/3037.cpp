////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 16:26:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3037
////Problem Title: 
////Run result: Accept
////Run time:1435MS
////Run memory:2384KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
using namespace std;

typedef long long ll;

ll powmod(ll a,ll b,ll MOD){
    ll ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}

ll fac[100005];
ll getfact(ll p){
    fac[0]=1;
    for(int i=1;i<=p;i++)
        fac[i]=(fac[i-1]*i)%p;
}
ll lucas(ll n,ll m,ll p){
    ll ret=1;
    while(n&&m){
        ll a=n%p,b=m%p;
        if(a<b) return 0;
        ret=(ret*fac[a]*powmod(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,p;
//        scanf("%I64d%I64d%I64d",&n,&m,&p);
        cin>>n>>m>>p;
        getfact(p);
        cout<<lucas(n+m,m,p)<<endl;
//        printf("%I64d\n",lucas(n+m,m,p));
    }
    return 0;
}



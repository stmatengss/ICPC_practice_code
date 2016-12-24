#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i) for(i=1;i<=n;i++)
using namespace std;
const int maxn=1004;
typedef long long ll;
int n;
ll t;
ll res[maxn];
pair<ll,int>w[maxn];
ll d[maxn],p;
pair<ll,int>k[maxn];

int main()
{
    int i,j;
    while(cin>>n>>t)
    {
        FOR(i) cin>>w[i].first,w[i].second=i;
        FOR(i) cin>>d[i];
        FOR(i) cin>>p,k[i].first=p-d[i]*t,k[i].second=i;
        sort(w+1,w+n+1);
        sort(k+1,k+n+1);
        FOR(i) res[k[i].second]=w[i].second;
        FOR(i) cout<<res[i]<<(i==n?"\n":" ");
    }
    return 0;
}

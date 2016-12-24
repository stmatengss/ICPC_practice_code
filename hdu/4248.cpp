////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-09 15:12:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4248
////Problem Title: 
////Run result: Accept
////Run time:1825MS
////Run memory:9820KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define FOR(i) for(i=0;i<n;i++)
#define FORN(i,n) for(i=0;i<n;i++)
#define FORBN(i,b,n) for(i=b;i<n;i++)
#define FORM(i,m) for(i=1;i<=m;i++)
#define FORBM(i,b,m) for(i=b;i<=m;i++)
#define IN(i) cin>>(i);
#define OUTS(i) cout<<(i);
#define OUT(i) cout<<(i)<<endl;
#define OUTMAT(a,i,n) cout<<(a)<<(i==n-1?"\n":" ");
#define INB(i) cin>>(i);if(i==0)break;
#define IFEQ(a,b,c) if(a==b)c++;
#define ZERO(a) a=0;
#define MAX(a,b,c) a=max(b,c);
#define CLR(a) memset(a,0,sizeof(a));
#define BFSQUE(a,b) a=b.front(); b.pop();
using namespace std;

typedef long long ll;
const ll mod=1000000007;
ll dp[10104];
ll c[114][10104];

void tab()
{
    int i,j;
    c[0][0]=1;
    FORM(i,10002)
    {
//        A[i]=(A[i-1]*i)%mod;
        c[0][i]=1;
        FORM(j,i)if(j<=102)
            c[j][i]=(c[j-1][i-1]+c[j][i-1])%mod;
    }
//    FORN(i,20)FORN(j,i+1)OUTMAT(c[j][i],j,i+1)
}

int main()
{
    int n,tcase=1;
    int i,j,k,l;
    int a[104];
    ll sum;
    ll res;
    tab();
    while(cin>>n)
    {

        FORM(i,n)IN(a[i]);
        CLR(dp)
        FORN(i,a[1]+1)dp[i]=1;
        sum=a[1];
        res=0;
        FORBM(i,2,n)
        {
            for(j=sum;j>=0;j--)
            {
                FORM(k,a[i])
                {
//                    FORM(l,k)
//                    {
//                        dp[j+k]=(dp[j+k]+dp[j]*c[l][j+1]%mod*c[l-1][k-1]%mod)%mod;
//                    }
                      dp[j+k]=(dp[j+k]+dp[j]*c[k][j+k]%mod)%mod;
//                        dp[i][j-l+a[i]-k]=(dp[i][j-l+a[i]-k]
//                        +(((dp[i-1][j]*c[l][j])%mod*c[k-l][sum+1-j])%mod
//                            *c[k-1][a[i]-1])%mod)%mod;
                }
            }
            sum+=a[i];
        }
        FORM(i,sum)res=(res+dp[i])%mod;
//        FORM(i,n)dp[n][0]=(dp[n][0]*A[a[i]])%mod;
        cout<<"Case "<<tcase++<<": "<<res<<endl;
    }
    return 0;
}

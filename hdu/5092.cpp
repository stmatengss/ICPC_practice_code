////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:10:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5092
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2024KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN=107;
const long long MAXM=2147483648;

int i,j,k,l,m,n,tr,t,tcase;
int ans[MAXN];
int rec[MAXN][MAXN];
long long mn;
long long dp[MAXN][MAXN],a[MAXN][MAXN];

int main()
{
    cin>>t;
    tcase=1;
    while (tcase<=t)
    {
        cout<<"Case "<<tcase<<endl;
        tcase++;
        memset(ans,0,sizeof(ans));
        memset(rec,0,sizeof(rec));
        memset(dp,0,sizeof(dp));
        cin>>n>>m;
        for (i=1;i<=n;i++)
        {
            a[i][0]=MAXM;
            a[i][m+1]=MAXM;
            dp[i][0]=MAXM;
            dp[i][m+1]=MAXM;
            for (j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for (j=1;j<=m;j++)
        {
            dp[1][j]=a[1][j];
            rec[1][j]=0;
        }
        for (i=2;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                tr=-1;
                mn=dp[i-1][j+tr];
                for (k=0;k<2;k++)
                {
                    if (dp[i-1][j+k]<=mn)
                    {
                        tr=k;
                        mn=dp[i-1][j+tr];
                    }
                }
                dp[i][j]=mn+a[i][j];
                rec[i][j]=tr;
            }
        }
        mn=MAXM;
        for (j=1;j<=m;j++)
        {
            if (dp[n][j]<=mn)
            {
                mn=dp[n][j];
                ans[n]=j;
            }
        }
        for (i=n-1;i>0;i--)
        {
            ans[i]=ans[i+1]+rec[i+1][ans[i+1]];
        }
        for (i=1;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[n]<<endl;
        /*
        for (i=1;i<=n;i++)
        {
            for (j=0;j<=m+1;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for (i=1;i<=n;i++)
        {
            for (j=0;j<=m+1;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for (i=1;i<=n;i++)
        {
            for (j=0;j<=m+1;j++)
            {
                cout<<rec[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        //*/
    }
    return 0;
}
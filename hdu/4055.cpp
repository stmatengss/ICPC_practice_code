////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 16:12:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4055
////Problem Title: 
////Run result: Accept
////Run time:1388MS
////Run memory:15400KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
char s[1004];
ll sum[1004][1004];
ll dp[1004][1004];

int main()
{
    int n;
    int i,j;
    while(gets(s))
    {
        n=strlen(s)+1;
        dp[1][1]=1;
        sum[1][1]=1;
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                if(s[i-2]=='I')
                    dp[i][j]=sum[i-1][j-1];
                if(s[i-2]=='D')
                    dp[i][j]=(sum[i-1][i-1]-sum[i-1][j-1]+mod)%mod;
                if(s[i-2]=='?')
                    dp[i][j]=sum[i-1][i-1];
                sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
            }
        }
        cout<<(sum[n][n]%mod)<<endl;
    }
    return 0;
}
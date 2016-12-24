////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 16:05:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1716KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long dp[127][127];

void tab()
{
    int i,j,k;
    dp[0][0]=1;
    for(i=1;i<=124;i++)
    {
        for(j=0;j<=124;j+=i)
        {
            for(k=0;k+j<=124;k++)
            {
                dp[i][k+j]+=dp[i-1][k];
            }
        }
    }
}

int main()
{
    tab();
    int n;
    while(cin>>n)
    {
        cout<<dp[n][n]<<endl;
    }
    return 0;
}

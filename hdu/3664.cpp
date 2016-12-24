////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:14:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3664
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:8708KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;
typedef long long ll;
ll dp[1004][1004]={0};
const int mod =1000000007;

void tab()
{
    int i,j;
    dp[1][0]=1;
    for(i=2;i<=1000;i++)
    {
        dp[i][0]=1;
        dp[i][i-1]=1;
        for(j=1;j<i-1;j++)
        {
            dp[i][j]=( (j+1)*dp[i-1][j]+(i-j)*dp[i-1][j-1] )%mod;
        }

    }
}


int main()
{
int n,k;
    tab();
    while(cin>>n>>k)
    {
        cout<<dp[n][k]<<endl;
    }
    return 0;
}
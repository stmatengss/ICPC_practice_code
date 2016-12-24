////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 16:00:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5366
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1572KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

long long dp[64];

int main()
{
    int n;
    dp[1]=1,dp[2]=2,dp[3]=3;
    for(int i=4;i<=60;i++)
    {
        dp[i]=dp[i-1]+dp[i-3]+1;
    }
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

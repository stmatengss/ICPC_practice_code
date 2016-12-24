////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 15:21:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1848KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[104][104];
int num[104][104];
int n;

int dfs(int x,int y)
{
    if(x==n)
    {
        return num[x][y];
    }
    if(dp[x][y])
        return dp[x][y];
    return dp[x][y]=max(dfs(x+1,y),dfs(x+1,y+1))+num[x][y];
}

int main()
{
    int i,j;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                cin>>num[i][j];
        }
        cout<<dfs(1,1)<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

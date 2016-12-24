////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 10:33:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1520
////Problem Title: 
////Run result: Accept
////Run time:577MS
////Run memory:2040KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int value[6004];
//int father[6004];
int dp[6004][2];
int used[6004]={0};
vector<int>son[6004];

void fun(int num)
{
    int i;
    for(i=0;i<son[num].size();i++)
    {
        fun(son[num][i]);
    }
    dp[num][0]=0;
    dp[num][1]=value[num];
    for(i=0;i<son[num].size();i++)
    {
        dp[num][0]+=max(dp[son[num][i]][0],dp[son[num][i]][1]);
        dp[num][1]+=dp[son[num][i]][0];
//        dp[son[num][i]][0]=max(dp[num][0],dp[num][1]);
//        dp[son[num][i]][1]=dp[num][0]+value[son[num][i]];
    }
}

int main()
{
    int x,y;
    int i,j,k;
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            cin>>n;
            break;
        }
        memset(dp,0,sizeof(dp));
        memset(used,0,sizeof(used));
        for(i=1;i<=n;i++)
        {
            cin>>value[i];
            son[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            son[y].push_back(x);
            used[x]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(used[i]==0)
            {
                fun(i);
                cout<<max(dp[i][0],dp[i][1])<<endl;
            }
        }
    }

//    cout << "Hello world!" << endl;
    return 0;
}

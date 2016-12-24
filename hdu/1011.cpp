////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 13:47:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1011
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int value[104];
int bug[104];
int dp[104][104];
vector<int>son[104];
int father[104];
int used[104];
int n,m;

void dfs(int num)
{
    int i,j,k;
    int tmp=(bug[num]+19)/20;
    used[num]=1;
    for(i=tmp;i<=m;i++)
    {
        dp[num][i]=value[num];
    }
    for(i=0;i<son[num].size();i++)
    {
        if(used[son[num][i]]==0)
        {
            dfs(son[num][i]);
            for(j=m;j>=tmp;j--)
            {
                for(k=1;k<=j-tmp;k++)
                {
                    dp[num][j]=max(dp[num][j],dp[son[num][i]][k]+dp[num][j-k]);
                }
            }
        }
    }
}

int main()
{
    int x,y;
    int i,j,k;
    while(cin>>n>>m,n!=-1&&m!=-1)
    {
        memset(used,0,sizeof(used));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            cin>>bug[i]>>value[i];
            son[i].clear();
        }
        for(i=1;i<=n-1;i++)
        {
            cin>>x>>y;
            son[x].push_back(y);
            son[y].push_back(x);
            father[y]=x;
        }
        if(m==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            dfs(1);
            cout<<dp[1][m]<<endl;
        }

    }
//    cout << "Hello world!" << endl;
    return 0;
}

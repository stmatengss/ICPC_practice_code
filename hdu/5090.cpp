////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:10:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5090
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1824KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[104];
bool used[104];
bool vis[104];
int father[104]={0};
int n,k,counter,num;

bool dfs(int x)
{
int i;
        for(i=0;i<g[x].size();i++)
        {
            if(!vis[g[x][i]])
            {
                vis[g[x][i]]=true;
                if(father[g[x][i]]==0||dfs(father[g[x][i]]))
                {
                    father[g[x][i]]=x;
                    return true;
                }
            }
        }
        return false;
}

int main()
{
    int t;
    int i,j;
    cin>>t;
    while(t--)
    {
        counter=0;
        fill(father,father+101,0);
        for(i=1;i<=n;i++)
            g[i].clear();
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
        cin>>num;
            for(j=0;j*k+num<=n;j++)
            {
                g[i].push_back(k*j+num);
            }
        }
        for(i=1;i<=n;i++)
        {
            fill(vis,vis+101,0);
            if(dfs(i))counter++;
        }
        if(counter==n)cout<<"Jerry"<<endl;
        else cout<<"Tom"<<endl;
    }

    return 0;
}
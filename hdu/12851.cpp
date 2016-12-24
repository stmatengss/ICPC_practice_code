////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-30 12:19:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1285
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxn=504;
int n,m;
vector<int>g[maxn];
int du[maxn];
vector<int>res;
int mp[maxn][maxn];

bool Topsort()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(du[j]==0)
            {
                du[j]=-1;
                res.push_back(j);
                for(k=1;k<=n;k++)
                {
                    if(mp[j][k])
                        du[k]--;
                }
                break;
            }
            /*if(j>n)
                return false;
                */
        }
    }
    return true;
}

bool topsort()
{
    int i,j;
    int now;
    priority_queue<int,vector<int>, greater<int> >q;
    for(i=1;i<=n;i++)
    {
        if(du[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        now=q.top(),q.pop();
        res.push_back(now);
//        cout<<now<<endl;
        for(i=0;i<g[now].size();i++)
        {
            du[g[now][i]]--;
            if(du[g[now][i]]==0)
                q.push(g[now][i]);
        }
    }
    if(res.size()==n)return true;
    return false;
}

int main()
{
    int x,y;
    int i,j;
    while(cin>>n>>m)
    {
        fill(du,du+n+1,0);
        memset(mp,0,sizeof(mp));
//        for(i=1;i<=n;i++)
//            g[i].clear();
        res.clear();
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(!mp[x][y])
            {
            mp[x][y]=1;
//            g[x].push_back(y);
            du[y]++;
        }}
        Topsort();
        for(i=0;i<res.size();i++)
        {
            cout<<res[i]<<(i==n-1?"\n":" ");
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

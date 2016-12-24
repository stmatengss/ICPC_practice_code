////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-26 11:58:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2463
////Problem Title: 
////Run result: Accept
////Run time:2823MS
////Run memory:14216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int maxn=10004;
int n,m;
//map<int,int>mp;
vector<int>g[maxn];
int used[maxn];
int father[maxn];

int bfs()
{
    int now,res=0;
    int i;
    fill(father,father+n+1,0);
    fill(used,used+n+1,0);
    queue<int>q;
    q.push(1);
    used[1]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0;i<g[now].size();i++)
            father[g[now][i]]=now;
        for(i=1;i<=n;i++)
        {
//            if(now!=i&&used[i]==0&&mp[now*n+i]==0)
            if(now!=i&&used[i]==0&&father[i]!=now)
            {
                used[i]=1;
                q.push(i);
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int i,j;
    int x,y;
    int tcase=1;
    while(cin>>n>>m,n,m)
    {
//        mp.clear();
        for(i=1;i<=n;i++)g[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
//            mp[x*n+y]=1,mp[y*n+x]=1;
        }
        printf("Case %d: %d\n",tcase++,bfs());
    }
//    cout << "Hello world!" << endl;
    return 0;
}

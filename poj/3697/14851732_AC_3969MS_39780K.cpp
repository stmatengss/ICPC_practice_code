#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int mod=10000121;
const int maxn=10004;
int n,m;
int mp[10000124];
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
            if(now!=i&&used[i]==0&&mp[(now*n+i)%mod]==0)
//            if(now!=i&&used[i]==0&&mp[now*n+i]==0)
//            if(now!=i&&used[i]==0&&father[i]!=now)
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
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)g[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            mp[(x*n+y)%mod]=1;
            mp[(y*n+x)%mod]=1;
//            g[x].push_back(y);
//            g[y].push_back(x);
//            mp[x*n+y]=1,mp[y*n+x]=1;
        }
        printf("Case %d: %d\n",tcase++,bfs());
    }
//    cout << "Hello world!" << endl;
    return 0;
}

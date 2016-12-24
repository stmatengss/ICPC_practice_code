////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-30 11:55:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1285
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn=504;
int n,m;
vector<int>g[maxn];
int du[504];
vector<int>res;


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
        for(i=1;i<=n;i++)
            g[i].clear();
        res.clear();
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            du[y]++;
        }
        topsort();
        for(i=0;i<res.size();i++)
        {
            cout<<res[i]<<(i==n-1?"\n":" ");
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

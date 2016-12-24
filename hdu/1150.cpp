////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 10:59:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1150
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>

using namespace std;

const int maxn=104;
int n,m;
vector<int> g[maxn];
int used[maxn];
int match[maxn];

bool dfs(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(used[g[x][i]]==0)
        {
            used[g[x][i]]=1;
            if(match[g[x][i]]==-1||dfs(match[g[x][i]]))
            {
                match[g[x][i]]=x;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int i;
    int res=0;
    fill(match,match+m,-1);
    for(i=0;i<=n-1;i++)
    {
        fill(used,used+n,0);
        if(dfs(i))res++;
    }
    cout<<res<<endl;
}

int main()
{
    int f,x,y;
    int i,j,k;
    while(cin>>n&&n!=0)
    {
        for(i=1;i<=n;i++)
            g[i].clear();
        cin>>m>>k;
        for(i=1;i<=k;i++)
        {
            cin>>f>>x>>y;
            if(x>0&&y>0)
            {
                g[x].push_back(y);
            }
        }
        solve();
    }
//    cout << "Hello world!" << endl;
    return 0;
}

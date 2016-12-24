////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 17:36:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1151
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1812KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

vector<int>g[204];
map<int,int>mp;
bool used[204];
int from[204];
int to[204];
int n,m;

bool match(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(used[g[x][i]]==false)
        {
            used[g[x][i]]=true;
            if(from[g[x][i]]==0||match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                to[x]=g[x][i];
                return true;
            }
        }
    }
    return false;
}

void hungry()
{
    int counter=0;
    fill(from,from+n+1,0);
    fill(to,to+n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(to[i]==0)
        {
            fill(used,used+n+1,false);
            if(match(i))counter++;
        }

    }
    cout<<(n-counter)<<endl;
}

int main()
{
    int t;
    int s,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
//        mp.clear();
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
//            if(mp[x+y*1000]==0)
            {
//                mp[x+y*1000]=1;
                g[x].push_back(y);
            }

        }
        hungry();
    }
//    cout << "Hello world!" << endl;
    return 0;
}

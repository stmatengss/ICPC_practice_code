////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-03 13:14:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxn=104;
int n,m;
int du[maxn],mp[maxn][maxn];

bool Topsort()
{
    int i,j,k;
    bool st;
    for(i=1;i<=n;i++)
    {
        st=true;
        for(j=1;j<=n;j++)
        {
            if(du[j]==0)
            {
                du[j]=-1;
                st=false;
                for(k=1;k<=n;k++)
                {
                    if(mp[j][k])
                        du[k]--;
                }
                break;
            }
        }
        if(st)return false;
    }
    return true;
}

int main()
{
    int i,j;
    int x,y;
    while(cin>>n>>m,n,m)
    {
        memset(du,0,sizeof(du));
        memset(mp,0,sizeof(mp));
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            if(mp[x+1][y+1]==0)
                mp[x+1][y+1]=1,du[y+1]++;
        }
        if(Topsort())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

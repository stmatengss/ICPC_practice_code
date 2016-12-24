////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 12:18:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char mp[104][104];
int n,m;
typedef pair<int,int> point;
queue<point>q;

inline bool illegal(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]=='@')return true;
    return false;
}

void bfs(int x,int y)
{
    int i,j;
    q.push(point(x,y));
    mp[x][y]='*';
    while(!q.empty())
    {
        x=q.front().first,y=q.front().second;
        q.pop();
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if(!(i==0&&j==0)&&illegal(x+i,y+j))
                {
                    mp[x+i][y+j]='*';
                    q.push(point(x+i,y+j));
                }
            }
        }
    }
}

int main()
{
    int i,j,res;
    while(cin>>n>>m,n,m)
    {
        res=0;
        gets(mp[0]);
        for(i=1;i<=n;i++)
            gets(mp[i]+1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                if(mp[i][j]=='@')
                {
                    bfs(i,j);
                    res++;
                }
        }
        cout<<res<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
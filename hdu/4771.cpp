////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-09 10:31:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4771
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define FOR(i) for(i=0;i<n;i++)
#define FORN(i,n) for(i=0;i<n;i++)
#define IN(i) cin>>(i);
#define OUTS(i) cout<<(i);
#define OUT(i) cout<<(i)<<endl;
#define OUTMAT(a,i,n) cout<<(a)<<(i==n-1?"\n":" ");
#define INB(i) cin>>(i);if(i==0)break;
#define IFEQ(a,b,c) if(a==b)c++;
#define ZERO(a) a=0;
#define MAX(a,b,c) a=max(b,c);
#define CLR(a) memset(a,0,sizeof(a));
#define BFSQUE(a,b) a=b.front(); b.pop();
using namespace std;

struct point{
    int x,y,rk;
    point(){}
    point(int x,int y,int rk):x(x),y(y),rk(rk){}
};
int n,m,k;
int res,ans;
char mp[104][104];
int used[104][104];
int dis[10][10];
int pos[10][2];
int dx[4]={ 0, 0, 1,-1};
int dy[4]={ 1,-1, 0, 0};
int seq[10];

inline bool legal(int x,int y)
{
    if(x<=n&&x>=1&&y<=m&&y>=1&&mp[x][y]!='#')return true;
    return false;
}

bool bfs(int p,int x,int y)
{
    int i,xx,yy;
    int counter=0;
    point tmp;
    queue<point>q;
    q.push(point(x,y,0));
    used[x][y]=1;
    while(!q.empty())
    {
        BFSQUE(tmp,q)
        x=tmp.x;
        y=tmp.y;
        if(mp[x][y]>='0'&&mp[x][y]<='7')
        {
            dis[p][mp[x][y]-'0']=tmp.rk;
            counter++;
        }
        if(counter==k+1)return true;
        FORN(i,4)
        {
            xx=x+dx[i],yy=y+dy[i];
            if(legal(xx,yy)&&used[xx][yy]==0)q.push(point(xx,yy,tmp.rk+1)),used[xx][yy]=1;
        }
    }
    return false;
}

int main()
{
    int i,j;
    int x,y;
    bool st;
    while(1)
    {
        st=false;
        INB(n) INB(m)
        FORN(i,n)FORN(j,m){IN(mp[i+1][j+1]) if(mp[i+1][j+1]=='@')pos[0][0]=i+1,pos[0][1]=j+1,mp[i+1][j+1]='0';}
        IN(k)
        FORN(i,k){IN(pos[i+1][0]) IN(pos[i+1][1]) mp[pos[i+1][0]][pos[i+1][1]]='0'+i+1;}
//        FORN(i,n){FORN(j,m)OUTS(mp[i+1][j+1]); cout<<endl;}
        FORN(i,k+1){CLR(used) if(bfs(i,pos[i][0],pos[i][1])==false){st=true;break;}}
        if(st)cout<<"-1"<<endl;
        else
        {
            res=1000000;
            FORN(i,k+1)seq[i]=i;
            do{
                ans=0;
                FORN(i,k)ans+=dis[seq[i]][seq[i+1]];
                res=min(res,ans);
            }while(next_permutation(seq+1,seq+k+1));
            cout<<res<<endl;
        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

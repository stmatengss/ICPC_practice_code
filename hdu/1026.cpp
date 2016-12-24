////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 16:46:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
char mp[104][104];
int rec[104][104][3];
int dx[4]={ 1,-1, 0, 0};
int dy[4]={ 0, 0, 1,-1};
int rx[10004],ry[10004],st[10004];

struct node{
    int x,y;
    int rk;
    node(){}
    node(int x,int y,int rk):x(x),y(y),rk(rk){}
    int operator <(const node &b)const{
        return rk>b.rk;
    }
};

priority_queue<node>pq;

void fail()
{
    printf("God please help our poor hero.\n");
}

void succees(int now)
{
    int i,j,k;
    int counter=0;
    int x,y,xx,yy;
    x=n,y=m;
    printf("It takes %d seconds to reach the target position, let me show you the way.\n",now);
    while(x!=1||y!=1)
    {
        rx[counter]=(x),ry[counter]=(y);
        st[counter]=(rec[x][y][2]);
        xx=rec[x][y][0];
        yy=rec[x][y][1];
        x=xx,y=yy;
        counter++;
    }
    rx[counter]=(x),ry[counter]=(y);
    st[counter]=(rec[x][y][2]);
    for(i=counter,j=1;i>=1;j++,i--)
    {
        if(st[i])
        {
            for(k=0;k<st[i];k++)
            {
                printf("%ds:FIGHT AT (%d,%d)\n",j,rx[i]-1,ry[i]-1);
                j++;
            }
        }
        printf("%ds:(%d,%d)->(%d,%d)\n",j,rx[i]-1,ry[i]-1,rx[i-1]-1,ry[i-1]-1);
    }
    if(st[0])
    {
        for(k=0;k<st[i];k++)
        {
            printf("%ds:FIGHT AT (%d,%d)\n",j,rx[i]-1,ry[i]-1);
            j++;
        }
    }
}

bool illegal(int x,int y)
{
    if(mp[x][y]!='X'&&x>=1&&x<=n&&y>=1&&y<=m)return true;
    return false;
}

void bfs()
{
    node now;
    int i,x,y,xx,yy,rk;
    while(!pq.empty())pq.pop();
    pq.push(node(1,1,0));
    mp[1][1]='X';
    while(!pq.empty())
    {
        now=pq.top();
        pq.pop();
        x=now.x,y=now.y;
        rk=now.rk;

        if(x==n&&y==m)
        {
            succees(now.rk);
            return;
        }
        for(i=0;i<=3;i++)
        {
            xx=x+dx[i],yy=y+dy[i];
            if(illegal(xx,yy))
            {
                rec[xx][yy][0]=x,rec[xx][yy][1]=y;
                if(mp[xx][yy]=='.')
                {
                    pq.push(node(xx,yy,rk+1));
                    rec[xx][yy][2]=0;
                }
                else
                {
                    pq.push(node(xx,yy,rk+mp[xx][yy]-'0'+1));
                    rec[xx][yy][2]=mp[xx][yy]-'0';
                }
                mp[xx][yy]='X';
            }
        }
    }
    fail();
}

int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(rec,0,sizeof(rec));
        gets(mp[0]);
        for(i=1;i<=n;i++)
            gets(mp[i]+1);
        bfs();
        printf("FINISH\n");
    }
//    cout << "Hello world!" << endl;
    return 0;
}
/*
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
*/

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int n,m;
struct point{
	int rank;
	int x,y;
	int status;
	point(int r,int x,int y,int s):rank(r),x(x),y(y),status(s){
		status=s;
	}
	point(){
	}
};
char mp[504][504];
bool sit[3][504][504];
int endx,endy;
int beginx[2],beginy[2];
point tmp=point();
const int dx[3][4]={{-2, 0, 0, 1},
					{ 1,-1, 0, 0},
					{ 0, 0, 2,-1}};
const int dy[3][4]={{ 0,-2, 1, 0},
					{ 0, 0, 2,-1},
					{ 1,-1, 0, 0}};
const int dr[3][4]={{ 2, 1, 1, 2},
					{ 1, 1, 0, 0},
					{ 2, 2, 0, 0}};
const int ddx[3]={0,0,1};
const int ddy[3]={0,1,0};

bool pending2(int x,int y)
{
	if(x<=n-1&&x>=2&&y>=2&&y<=m-1)
		return true;
	return false;
}

bool pending(int x,int y,int status)
{
	int xx,yy;
	if(pending2(x,y)==false)
		return false;
	if(status==0)
	{
		if(mp[x][y]=='.'||mp[x][y]=='O')
			return true;
		return false;
	}
	else
	{
		xx=x+ddx[status],yy=y+ddy[status];
		if(pending2(xx,yy)==false||mp[x][y]=='#'||mp[xx][yy]=='#')
			return false;
		if(mp[x][y]=='.'||mp[xx][yy]!='.')
			return true;
		if(mp[x][y]=='E'||mp[xx][yy]=='E')
		{
			if(mp[x][y]=='E'&&mp[xx][yy]=='E')
				return true;
			return false;
		}
		return true;
	}
}

int main()
{
	int i,j,k;
	int counterbegin;
	int succeed;
	int x,y,yy,xx,rank,status,status2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		counterbegin=0;
		succeed=0;
		memset(sit,0,sizeof(sit));
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",&mp[i][j]);
				if(mp[i][j]=='X')
				{
					beginy[counterbegin]=j;
					beginx[counterbegin]=i;
					counterbegin++;
				}
				if(mp[i][j]=='O')
				{
					endx=i,endy=j,mp[endx][endy]='.';
				}
			}
		}
		queue<point>st;
		if(counterbegin==2)
		{
			if(beginx[0]==beginx[1])
			{
				st.push(point(0,beginx[0],min(beginy[0],beginy[1]),1));
			}
			else
			{
				st.push(point(0,min(beginx[1],beginx[0]),beginy[0],2));
			}
		}
		else
		{
				st.push(point(0,beginx[0],beginy[0],0));
		}
		while(!st.empty())
		{
			tmp=st.front();
			st.pop();
			x=tmp.x,y=tmp.y,rank=tmp.rank,status=tmp.status;
			if(x==endx&&y==endy&&status==0)
			{
				succeed=1;
				cout<<tmp.rank<<endl;
			}
			for(j=0;j<4;j++)
			{
				xx=x+dx[status][j],yy=y+dy[status][j],status2=dr[status][j];
				if(sit[status2][xx][yy]==0&&pending(xx,yy,status2))
				{
					st.push(point(rank+1,xx,yy,status2));
					sit[status2][xx][yy]=1;
				}
			}
		}
		if(!succeed)
			cout<<"Impossible"<<endl;
	}
	return 0;
}
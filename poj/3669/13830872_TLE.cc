#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

const int N=305;
struct point{
	int x;
	int y;
	int t;
	point(){}
	point(int a,int b,int c): x(a),y(b),t(c){}	
};
queue< point >q; 
int map[N][N]={0};
int m,n;
int x,y,t;
int ST=0;
point p;

int main()
{
	int i,j;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>t;
		if(map[x][y]==0)map[x][y]=t;
		if(map[x][y+1]==0)map[x][y+1]=t;
		if(map[x+1][y]==0)map[x+1][y]=t;
		if(map[x-1][y]==0&&x>0)map[x-1][y]=t;
		if(map[x][y-1]==0&&y>0)map[x][y-1]=t;
	}
	q.push( point(0,0,0) );
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		x=p.x;
		y=p.y;
		t=p.t;
		if(map[x][y]==0)
		{
			cout<<(t)<<endl;
			ST=1;
			break;
		}
		if(t>=map[x][y])continue;
		q.push( point(x,y,t+1));
		q.push( point(x+1,y,t+1));
		q.push( point(x,y+1,t+1));
		if(x>0)q.push( point(x-1,y,t+1));
		if(y>0)q.push( point(x,y-1,t+1));
	}
	if(ST==0)cout<<"-1"<<endl;	
	return 0;
}

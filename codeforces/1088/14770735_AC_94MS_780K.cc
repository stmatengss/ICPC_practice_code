#include<iostream>
#include<cstdio>

using namespace std;

int n,m;
int num[104][104];
int dp[104][104];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int x,int y)
{
	int i,xx,yy;
	if(dp[x][y])
		return dp[x][y];
	for(i=0;i<=3;i++)
	{
		xx=x+dx[i],yy=y+dy[i];
		if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&num[x][y]>num[xx][yy])
			dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
	}
	return dp[x][y];
}

int main()
{
	int res=-1;
	int i,j,k;
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>num[i][j];
			}
		}
		res=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				res=max(dfs(i,j),res);
			}
		}
		cout<<res+1<<endl;
	}
	return 0;
}
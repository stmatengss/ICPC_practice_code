#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,m;
int used[30][30];
pair<int,int> res[65];
int dy[8]={-1, 1,-2, 2,-2, 2,-1, 1};
int dx[8]={-2,-2,-1,-1, 1, 1, 2, 2};

bool pending(int x,int y)
{
	if(x<=n&&x>=1&&y<=m&&y>=1)
		return true;
	return false;
}

bool dfs(int x,int y,int counter)
{
	int xx,yy,i;
//	used[x][y]
	res[counter].first=x,res[counter].second=y;
	if(counter==n*m)
	{
		return true;
	}
	for(i=0;i<=7;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(pending(xx,yy)&&used[xx][yy]==0)
		{
			used[xx][yy]=1;
			if(dfs(xx,yy,counter+1))
				return true;
			used[xx][yy]=0;
		}
	}
	return false;
}

bool solve()
{
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			memset(used,0,sizeof(used));
//			res.clear();
			used[i][j]=1;
			if(dfs(i,j,1))
				return true;
		}
	return false;
}

int main()
{
	int i,j,k;
	int t,counter=0;
	cin>>t;
	while(t--)
	{
		counter++;
		cin>>m>>n;
		cout<<"Scenario #"<<counter<<':'<<endl;
		if(solve())
		{
			for(i=1;i<=n*m;i++)
				cout<<(char)('A'+res[i].first-1)<<(res[i].second);
			cout<<endl;
		}
		else
		{
			cout<<"impossible"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
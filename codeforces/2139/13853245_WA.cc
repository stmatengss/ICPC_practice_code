#include<iostream>
#include<cstdio>
#define INF 1<<30
using namespace std;

const int N=304; 
int dis[N][N];
int movie[N];

int main()
{
	int n,m,t;
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	for(i=1;i<=m;i++)
	{
		cin>>t;
		for(j=1;j<=t;j++)
			cin>>movie[j];	
		for(j=1;j<=t;j++)
			for(k=1;k<=t;k++)
				if(j!=k)dis[movie[j]][movie[k]]=1;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j&&dis[i][k]!=0&&dis[k][j]!=0)
				{
					dis[i][j]=dis[i][j]<dis[i][k]+dis[k][j]?dis[i][j]:dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int min_=INF,ans;
	for(i=1;i<=n;i++)
	{
		ans=0;
		for(j=1;j<=n;j++)
		{
			ans+=dis[i][j];	
		}
		ans=100*ans/(n-1);
		if(ans<min_)min_=ans;		
	}
	cout<<(min_)<<endl;
	return 0;
} 
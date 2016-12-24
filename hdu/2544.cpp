////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-10 00:39:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:392KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 100000

using namespace std;

int d[104],dis[104][104],flag[104]={0};
int i,j,k;
int a,b,c;
int n,m;
int min_;

int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++)d[i]=MAX;
		d[1]=0;
		for(i=1;i<=n;i++)
		   for(j=1;j<=n;j++)
		   {
		    dis[i][j]=MAX;
		   }
		for(i=1;i<=m;i++)
		{
			cin>>a>>b>>c;
			if(c<dis[a][b])
			{
			dis[a][b]=c;
			dis[b][a]=c;
		    }
		}
		for(i=1;i<=n;i++)
		{
			min_=MAX;
			for(j=1;j<=n;j++)
			{
				if(!flag[j]&&d[j]<min_)
				{
				   min_=d[j];
				   k=j;
			    }
			}
			flag[k]=1;
			for(j=1;j<=n;j++)
			{
				if(!flag[j]&&d[j]>d[k]+dis[k][j]&&dis[k][j]!=MAX)
				d[j]=d[k]+dis[k][j];
			}
		}
		cout<<d[n]<<endl;
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-10 00:07:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:432KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 99999
int dis[202][202];
int n,m,s,t,a,b,x;
int i,j,k;

int main()
{
	while(cin>>n>>m)
	{
	
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   	  if(i==j)dis[i][j]=0;
	   	  else dis[i][j]=MAX;
	   }
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>x;
		if(x<dis[a][b])
		{
		dis[a][b]=x;
		dis[b][a]=x;
	    }
	}
	for(k=0;k<n;k++)
	   for(i=0;i<n;i++)
	      for(j=0;j<n;j++)
	      {
	      	if(dis[i][j]>dis[i][k]+dis[k][j]&&dis[i][k]!=MAX&&dis[k][j]!=MAX)
	      	dis[i][j]=dis[i][k]+dis[k][j];
	      }
	cin>>s>>t;
	if(dis[s][t]!=MAX)
	cout<<dis[s][t]<<endl;
	else cout<<"-1"<<endl;
    }
	return 0;
}
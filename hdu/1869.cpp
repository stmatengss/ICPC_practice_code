////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-10 00:19:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:408KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#define MAX 99999
using namespace std;

int dis[200][200];
int m,n;
int i,j,k;
int a,b;
int ST;

int main()
{
	while(cin>>n>>m)
	{
		ST=0;
		for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		   if(i==j)dis[i][i]=0;
		   else dis[i][j]=MAX;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		dis[a][b]=1;
		dis[b][a]=1;
	}
	for(k=0;k<n;k++)
	   for(i=0;i<n;i++)
	      for(j=0;j<n;j++)
	      {
	      	if(dis[i][j]>dis[i][k]+dis[k][j]&&dis[i][k]!=MAX&&dis[k][j]!=MAX)
	      	dis[i][j]=dis[i][k]+dis[k][j];
	      }
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   	if(dis[i][j]>7){
	   		ST=1;
	   		break;
	   	}
	   }
	   if(ST)cout<<"No"<<endl;
	   else cout<<"Yes"<<endl;
    }
	return 0;
}
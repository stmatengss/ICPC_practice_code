////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-22 11:33:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:424KB
//////////////////System Comment End//////////////////
/*
	Name: 
	Copyright: 
	Author: 
	Date: 20/11/14 23:39
	Description: 
*/
#include<iostream>
#define N 10000
#include<algorithm>
using namespace std;

int u[N],v[N],w[N],p[N],hash[N];
int m,n;
int i,j;
int sum,ans,counter;
int temp;
int st,x,y;

int cmp(const int i,const int j)
{
	return (w[i]<w[j]);
}

int find(int x)
{
	return x==p[x]?p[x]:find(p[x]);
}

int main()
{
	while(cin>>m>>n)
	{
		if(m==0)break;
		sum=0;
		st=0;
		ans=0;
		for(i=0;i<m;i++)
		{
			hash[i]=i;
			cin>>u[i]>>v[i]>>w[i];
		}
		
		for(i=1;i<=n;i++)p[i]=i;
		
		sort(hash,hash+m,cmp);
		
		for(i=0;i<m;i++)
		{
			temp=hash[i];
			if((x=find(v[temp]))!=(y=find(u[temp])))
			{
				sum+=w[temp];
				p[x]=y;
				st++;
			}
		}
		
//		for(i=1;i<=n;i++)
//		if(p[i]==i)st++;
		if(st!=n-1)cout<<"?"<<endl;
		else cout<<sum<<endl;
	}
	return 0;
	
}
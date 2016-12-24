////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-22 13:37:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:488KB
//////////////////System Comment End//////////////////
/*
	Name: 
	Copyright: 
	Author: 
	Date: 22/11/14 12:28
	Description: 
*/


#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct point{
	int x;
	int y;
};

int v[10000],u[10000],hash[10000],p[120];
int m,n;
int i,j,counter,st,temp,x,y;
double sum,ans,len,w[10000];
point po[120];

int find(int x)
{
	return p[x]==x?x:find(p[x]);
}

int cmp(const int i,const int j)
{
	return int(w[i]<w[j]);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		counter=0;
		st=0;
		for(i=1;i<=n;i++)
		   cin>>po[i].x>>po[i].y;
		   
		for(i=1;i<=n;i++)p[i]=i;
		
		for(i=1;i<=n;i++)
		   for(j=i+1;j<=n;j++)
		   {
		   	   len=sqrt(double(po[i].x-po[j].x)*(po[i].x-po[j].x)+double(po[i].y-po[j].y)*1.0*(po[i].y-po[j].y));
			   //len=sqrt(len);
			   if(len>=10.0&&len<=1000.000001)
			   {
			   	  v[counter]=i;
			   	  u[counter]=j;
			   	  w[counter]=len;
			   	  hash[counter]=counter;
			   	  counter++;
			   } 
		   }
		m=counter;
		
//		if(m<n-1)
//		{
//			cout<<"oh!"<<endl;
//		}
		
		sort(hash,hash+m,cmp);
		
		for(i=0;i<=m;i++)
		{
			temp=hash[i];
			if((x=find(u[temp]))!=(y=find(v[temp])))
			{
				st++;
				sum+=w[temp];
				p[x]=y;
			}
		}
		sum*=100;
		if(st!=n-1)cout<<"oh!"<<endl;
		else printf("%.1lf\n",sum);
	}
	return 0;
}
/*
2
4
0 0
100 100
0 100
200 0
*/
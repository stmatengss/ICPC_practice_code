////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-16 19:18:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include<iostream>
#define N 1004
using namespace std;

int father[N];

void init(int n)
{
	int i;
	for(i=1;i<=n;i++)father[i]=i;
}

int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
	
}

void unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)father[x]=y;
}

int main()
{
	int i;
	int n,m,x,y,counter;
	while(cin>>n)
	{
		if(n==0)break;
		cin>>m;
		init(n);
		counter=0;
		for(i=1;i<=m;i++)
		{
		   cin>>x>>y;
		   unit(x,y);
	    }
        for(i=1;i<=n;i++)
           if(i==find(i))counter++;
        cout<<counter-1<<endl;
	}	
	return 0;
}
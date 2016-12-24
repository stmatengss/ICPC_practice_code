////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-16 00:18:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;


int father[1010];

void init( int a[])
{
	for (int i = 1; i <= 1010; i++)
	{
		a[i]=i;
	}
}

int find(int x)
{
	if (x!=father[x])
	{
		father[x]=find(father[x]);
	}
	return father[x];
}

main()
{
	int n,m;
	int x,y;
	int count;
	int fatherX,fatherY;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0)
		{
			return;
		}
		count=-1;
		init(father);
		scanf("%d",&m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d",&x,&y);
			fatherX=find(x);
			fatherY=find(y);
			if (fatherX!=fatherY)
			{
				father[fatherX]=fatherY;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (father[i]==i)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
        //return 0;
}
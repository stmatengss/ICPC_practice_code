////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-07 14:52:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:780MS
////Run memory:5692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=1<<20;
int TA[maxn];
int n;

int sum(int x)
{
	int res=0;
	for(int i=x;i>0;i-=(i&-i))
	{
		res+=TA[i];
	}
	return res;
}

void add(int x,int value)
{
	for(int i=x;i<=n;i+=(i&-i))
	{
		TA[i]+=value;
	}
}

int main()
{
	int i;
	int a,b;
	while(cin>>n)
	{
		memset(TA,0,sizeof(TA));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,1);
			add(b+1,-1);
		}
		for(i=1;i<=n;i++)
		{
			printf("%d%c",sum(i),i!=n?' ':'\n');
		}
	}
	return 0;
}
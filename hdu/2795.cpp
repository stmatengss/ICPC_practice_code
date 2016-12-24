////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-05 20:25:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:2886MS
////Run memory:3796KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=1<<20+2;

int sum[maxn];
int n,m;

void init(int left,int right,int u)
{
	if(left==right)
	{
		sum[u]=m;
		return;
	}
	int mid=(left+right)>>1;
	init(left,mid,2*u);
	init(mid+1,right,2*u+1);
	sum[u]=max(sum[2*u],sum[2*u+1]);
}

int update(int value,int left,int right,int u)
{
	if(left==right)
	{
		sum[u]-=value;
		return left;
	}
	int mid=(left+right)>>1;
	int res;
	if(sum[u*2]>=value)
		res=update(value,left,mid,2*u);
	else
		res=update(value,mid+1,right,2*u+1);
	sum[u]=max(sum[2*u],sum[2*u+1]);
	return res;
}

//int query(int l,int r,int left,int right,int u)
//{
//	if(l<=left&&r>=right)
//	{
//		return sum[u];
//	}
//	int mid=(left+right)>>1;
//	int res=-1;
//	if(l<=mid)
//	{
//		res=max(res,query(l,r,left,mid,2*u));
//	}
//	if(r>mid)
//	{
//		res=max(res,query(l,r,mid+1,right,2*u+1));
//	}
//	return res;
//}

int main()
{
	int i,j;
	int tcase=0;
	int t;
	int x,y;
	while(~scanf("%d%d%d",&n,&m,&t))
	{
		if(t<n)
			n=t;
		init(1,n,1);
		for(i=1;i<=t;i++)
		{
			scanf("%d",&x);
			if(x>sum[1])
				puts("-1");
			else
				printf("%d\n",update(x,1,n,1));
		}
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-07 20:50:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:998MS
////Run memory:4180KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100000;

int sum[maxn*4+1];
int lazy[maxn*4+1];
//int num[maxn>>1];
int n;

void init(int left,int right,int u)
{
	if(left==right)
	{
		sum[u]=1;
		return;
	}
	int mid=(left+right)>>1;
	init(left,mid,2*u);
	init(mid+1,right,2*u+1);
	sum[u]=sum[2*u]+sum[2*u+1];
}

void pushup(int u,int len)
{
	if(lazy[u]>0)
	{
		lazy[2*u]=lazy[2*u+1]=lazy[u];
		sum[2*u]=(len-(len>>1))*lazy[u];
		sum[2*u+1]=(len>>1)*lazy[u];
		lazy[u]=0;
	}
}

void update(int l,int r,int value,int left,int right,int u)
{
	if(l<=left&&r>=right)
	{
  		lazy[u]=value;
		sum[u]=lazy[u]*(right-left+1);
		return;
	}
	pushup(u,right-left+1);
	int mid=(left+right)>>1;
	if(l<=mid)
		update(l,r,value,left,mid,2*u);
	if(r>mid)
		update(l,r,value,mid+1,right,2*u+1);
	sum[u]=sum[2*u]+sum[2*u+1];
}

int query(int l,int r,int left,int right,int u)
{
	if(l<=left&&r>=right)
	{
		return sum[u];
	}
	int mid=(left+right)>>1;
	int res=0;
	if(l<=mid)
	{
		res+=query(l,r,left,mid,2*u);
	}
	if(r>mid)
	{
		res+=query(l,r,mid+1,right,2*u+1);
	}
	return res;
}

int main()
{
	int i,j;
	int tcase=0;
	int t;
	int m;
	int x,y,v;
	cin>>t;
//	char op[10];
	while(t--)
	{
		tcase++;
		memset(lazy,0,sizeof(lazy));
		scanf("%d%d",&n,&m);
		init(1,n,1);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			update(x,y,v,1,n,1);
		}
		printf("Case %d: The total value of the hook is ",tcase);
		printf("%d.\n",sum[1]);
	}
	return 0;
}
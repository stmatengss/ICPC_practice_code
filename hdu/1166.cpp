////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-05 15:29:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:2512KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1<<18+2;

int sum[maxn];
int num[maxn>>1];
int n;

void init(int left,int right,int u)
{
	if(left==right)
	{
		sum[u]=num[left];
		return;
	}
	int mid=(left+right)>>1;
	init(left,mid,2*u);
	init(mid+1,right,2*u+1);
	sum[u]=sum[2*u]+sum[2*u+1];
}

void update(int pos,int value,int left,int right,int u)
{
	if(left==right)
	{
		sum[u]+=value;
		return;
	}
	int mid=(left+right)>>1;
	if(pos<=mid)
		update(pos,value,left,mid,2*u);
	else
		update(pos,value,mid+1,right,2*u+1);
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
	int x,y;
	cin>>t;
	char op[10];
	while(t--)
	{
		tcase++;
		printf("Case %d:\n",tcase);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		init(1,n,1);
		while(true)
		{
			scanf("%s",op);
			if(op[0]=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",query(x,y,1,n,1));
			}
			else if(op[0]=='A')
			{
				scanf("%d%d",&x,&y);
				update(x,y,1,n,1);
			}
			else if(op[0]=='S')
			{
				scanf("%d%d",&x,&y);
				update(x,-y,1,n,1);
			}
			else if(op[0]=='E')
			{
				break;
			}
		}
	}
	return 0;
}
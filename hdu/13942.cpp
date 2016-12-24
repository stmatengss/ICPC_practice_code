////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-05 16:44:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:5692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn=1<<18+2;

int sum[maxn];
int num[maxn>>1];
int n;

void init(int left,int right,int u)
{
	if(left==right)
	{
		sum[u]=0;
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

int res,ans;

int main()
{
	int i,j,k;
	while(~scanf("%d",&n))
	{
		memset(sum,0,sizeof(sum));
		ans=0;
		init(1,n,1);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			ans+=query(num[i]+1,n,1,n,1);
			update(num[i],1,1,n,1);
		}
		
		res=ans;
		for(i=0;i<n;i++)
		{
			res=res-num[i]+(n-num[i]-1);
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}

	return 0;
}
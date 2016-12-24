////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-07 20:45:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:951MS
////Run memory:4156KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
#include <vector>
#define LL __int64
using namespace std;

const int maxn=100005;

int sum[maxn*4];					//区间和
int setv[maxn*4];					//区间的值

void build(int o,int L,int R)		//建树过程
{
	if(L==R)
	{
		sum[o]=1;					//初始都为1
		return;
	}
	int M=(L+R)>>1;	
	build(o*2,L,M);					//左子树
	build(o*2+1,M+1,R);				//右子树
	sum[o]=sum[o*2+1]+sum[o*2];		//当前区间的和为左右子树的和
}

void pushdown(int o,int l)
{					
	if(setv[o]>0)							//若此区间已经被覆盖
	{
		setv[o*2]=setv[o*2+1]=setv[o];		//沿着左右子树传递下去
		sum[o*2]=(l-(l>>1))*setv[o];		//左子树的和为这个区间的值乘以长度
		sum[o*2+1]=(l>>1)*setv[o];			//同理求右子树的和
		setv[o]=0;							//清除这个区间的标记
	}
}

void update(int o,int v,int L,int R,int l,int r)
{
	if(l<=L && r>=R)
	{
		setv[o]=v;							//若完全覆盖，则标记为v，代表这个区间的值
		sum[o]=setv[o]*(R-L+1);				//这个区间的和为区间值乘以长度
	}
	else
	{
		pushdown(o,R-L+1);
		int M=(L+R)>>1;
		if(l<=M)
			update(o*2,v,L,M,l,r);			//往左子树传递更新
		if(r>M)
			update(o*2+1,v,M+1,R,l,r);		//往右子树传递更新
		sum[o]=sum[o*2]+sum[o*2+1];			
	}
}

int main()
{
	int t,n,m,cont=1;
	scanf("%d",&t);
	while(t--)
	{
		memset(setv,0,sizeof(setv));
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&m);
		while(m--)
		{
			int l,r,v;
			scanf("%d%d%d",&l,&r,&v);
			update(1,v,1,n,l,r);
		}
		printf("Case %d: The total value of the hook is ",cont++);
		printf("%d.\n",sum[1]);
	}
	return 0;
}
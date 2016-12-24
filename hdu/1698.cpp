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

int sum[maxn*4];					//�����
int setv[maxn*4];					//�����ֵ

void build(int o,int L,int R)		//��������
{
	if(L==R)
	{
		sum[o]=1;					//��ʼ��Ϊ1
		return;
	}
	int M=(L+R)>>1;	
	build(o*2,L,M);					//������
	build(o*2+1,M+1,R);				//������
	sum[o]=sum[o*2+1]+sum[o*2];		//��ǰ����ĺ�Ϊ���������ĺ�
}

void pushdown(int o,int l)
{					
	if(setv[o]>0)							//���������Ѿ�������
	{
		setv[o*2]=setv[o*2+1]=setv[o];		//������������������ȥ
		sum[o*2]=(l-(l>>1))*setv[o];		//�������ĺ�Ϊ��������ֵ���Գ���
		sum[o*2+1]=(l>>1)*setv[o];			//ͬ�����������ĺ�
		setv[o]=0;							//����������ı��
	}
}

void update(int o,int v,int L,int R,int l,int r)
{
	if(l<=L && r>=R)
	{
		setv[o]=v;							//����ȫ���ǣ�����Ϊv��������������ֵ
		sum[o]=setv[o]*(R-L+1);				//�������ĺ�Ϊ����ֵ���Գ���
	}
	else
	{
		pushdown(o,R-L+1);
		int M=(L+R)>>1;
		if(l<=M)
			update(o*2,v,L,M,l,r);			//�����������ݸ���
		if(r>M)
			update(o*2+1,v,M+1,R,l,r);		//�����������ݸ���
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
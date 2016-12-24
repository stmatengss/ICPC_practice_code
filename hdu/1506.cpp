////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 18:57:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1506
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:4132KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
const int maxn=100004;
int n;
ll l[maxn],r[maxn];
ll h[maxn],st[maxn];

void solve()
{
	int i,j;
	int t=0;
	for(i=1;i<=n;i++)
	{
		while(t>0&&h[st[t-1]]>=h[i])t--;
		l[i]=t==0?1:(st[t-1]+1);
		st[t++]=i;
	}
	t=0;
	for(i=n;i>=1;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i])t--;
		r[i]=t==0?n+1:(st[t-1]);
		st[t++]=i;
	}
	long long res=0;
	for(i=1;i<=n;i++)
	{
		res=max(res,h[i]*(r[i]-l[i]));
	}
//	cout<<res<<endl;
	printf("%lld\n",res);
}

int main()
{
	int i;
	while(cin>>n)
 	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
		}
  		solve();
	}
	return 0;
}
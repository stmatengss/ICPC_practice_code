////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 20:09:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1505
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
const int maxn=1004;
int n,m;
int l[maxn],r[maxn];
int h[maxn],st[maxn];
int len[maxn];
//char tmp[maxn];
char tmp;

ll solve()
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
		res=max(res,(ll)h[i]*(r[i]-l[i]));
	}
//	cout<<res<<endl;
	return res;
//	printf("%lld\n",res);
}

int main()
{
	int i,j;
	int t;
	cin>>t;
	ll res;
	while(t--)
 	{
		cin>>m>>n;
  		res=0;
  		memset(len,0,sizeof(len));
		for(i=1;i<=m;i++)
		{
			
			for(j=1;j<=n;j++)
			{
				cin>>tmp;
				if(tmp=='F')
				{
					h[j]=len[j]+1;
				}
				else
				{
					h[j]=0;
				}
				len[j]=h[j];
			}
			res=max(res,solve());
		}
  		cout<<res*3<<endl;
	}
	return 0;
}
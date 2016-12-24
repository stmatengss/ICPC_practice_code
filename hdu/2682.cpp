////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-31 23:56:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2682
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:10052KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=2000004;
int isprime[maxn+3];
int n,m;

struct edge{
	int x,y,v;
	edge(){
	}
	edge(int x,int y,int v):x(x),y(y),v(v){
	}
	int operator <(const edge& a)const{
		return v<a.v;
	}
};
edge e[200004];
int num[604];
int father[604];
int rk[604];

int find(int x)
{
	if(x==father[x])return x;
	return father[x]=find(father[x]);
}

bool unin(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return false;
	if(rk[x]>rk[y])
	{
		father[y]=x;
	}
	else
	{
		if(rk[x]==rk[y])rk[x]++;
		father[x]=y;
	}
	return true;
}

void table()
{
	int i,j;
	isprime[1]=1;
	isprime[0]=1;
	for(i=2;i<=maxn;i++)
	{
		if(isprime[i]==0)
		{
			for(j=2*i;j<=maxn;j+=i)
				isprime[j]=1;
		}
	}
}

void kuskal()
{
	int i;
	sort(e,e+m);
	int counter=0;
	bool flag=true;
	long long res=0;
	for(i=0;i<m;i++)
	{
		if(unin(e[i].x,e[i].y))
		{
			counter++;
			res+=e[i].v;
		}
		if(counter==n-1)
		{
			flag=false;
			break;
		}
	}
	if(flag)cout<<"-1"<<endl;
	else cout<<res<<endl;
}

void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
		rk[i]=0;
	}
}

int main()
{
	int i,j;
	table();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		m=0;
		init();
		for(i=1;i<=n;i++)
		{
			cin>>num[i];
			for(j=1;j<i;j++)
			{
				if(isprime[num[i]]==0||isprime[num[j]]==0||isprime[num[i]+num[j]]==0)
				{
					e[m++]=edge(i,j,min(num[i],min(num[j],abs(num[i]-num[j]))));
				}
			}
		}
		kuskal();
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-15 21:05:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

map<int,int>mp;
struct node{
	int dead,cost;
	int operator <(const node &a)const
	{
		if(cost==a.cost)return dead<a.dead;
		return cost>a.cost;
	}
};
node v[2002];
int n;
int st;
int res;

int main()
{
	int t;
	int i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=0;
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i].dead);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i].cost);
		}
		sort(v,v+n);
		for(i=0;i<n;i++)
		{
			st=1;
			for(j=v[i].dead;j>=1;j--)
			{
				if(mp[j]!=1)
				{
					st=0;
					mp[j]=1;
					break;
				}
			}
			if(st)res+=v[i].cost;
		}
		cout<<res<<endl;
	}
	
}

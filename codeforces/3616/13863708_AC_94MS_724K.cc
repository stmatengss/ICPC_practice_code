#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[1007]={0},n,m,r;
struct seg{
	int begin;
	int end;
	int w;
};
seg a[1007];

int cmp(seg x,seg y)
{
	if(x.begin!=y.begin)return x.begin<y.begin;
	return x.end<y.end;
}

int main()
{
	int i,j,MAX=0;
	cin>>n>>m>>r;
	for(i=1;i<=m;i++)
		cin>>a[i].begin>>a[i].end>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<i;j++)
			if(a[j].end+r<=a[i].begin)
			dp[i]=max(dp[i],dp[j]);
		dp[i]+=a[i].w;
	}
	for(i=1;i<=m;i++)
		MAX=dp[i]>MAX?dp[i]:MAX;
	cout<<MAX<<endl;	
} 
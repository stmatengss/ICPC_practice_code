#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int dp[1004][32];
int tree[1004];

int main()
{
	int n,t,MAX=0,m;
	int i,j;
	cin>>n>>t;
	t++;
	for(i=1;i<=n;i++)
		cin>>tree[i];
	dp[0][0]=0;
	dp[0][1]=0;
	for(i=1;i<=t;i++)
	{
		if(i%2==1&&tree[i]==1)
			dp[i][i]=dp[i-1][i-1]+1;
		else if(i%2==0&&tree[i]==2)
			dp[i][i]=dp[i-1][i-1]+1;
		else
			dp[i][i]=dp[i-1][i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(tree[i]==1)
			dp[i][1]=dp[i-1][1]+1;
		else
			dp[i][1]=dp[i-1][1];
	}
	for(i=3;i<=n;i++)
		for(j=2;j<i&&j<=t;j++)
		{
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
			if(j%2==1&&tree[i]==1)dp[i][j]++;
			if(j%2==0&&tree[i]==2)dp[i][j]++;
		}
	m=min(n,t);
	for(i=1;i<=m;i++)
	{
		MAX=max(dp[n][i],MAX);
	}
	cout<<MAX<<endl;
	return 0;
}
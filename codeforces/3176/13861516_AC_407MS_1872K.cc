#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[400][400];
int n;
int num[400][400];

int main()
{
	int i,j;
	cin>>n;
	int Max=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			cin>>num[i][j];
		}
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			if(j==1) dp[i][1]=dp[i-1][1]+num[i][1];
			else if(j==i) dp[i][j]=dp[i-1][j-1]+num[i][j];
			else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+num[i][j];
		}
	for(i=1;i<=n;i++)Max=max(Max,dp[n][i]);
	cout<<Max<<endl;
	return 0;
}
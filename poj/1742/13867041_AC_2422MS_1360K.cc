#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[104],c[104],n,m,dp[100004];

int main()
{
	int i,j,k;
	while(cin>>n>>m&&n!=0&&m!=0)
	{
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>c[i];
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(dp[j]>=0)dp[j]=c[i];
			else if(dp[j-a[i]]<0||j<a[i])dp[j]=-1;
			else dp[j]=dp[j-a[i]]-1;
		}
	}
	int counter=0;
	for(j=1;j<=m;j++)if(dp[j]>=0)counter++;
	cout<<counter<<endl;		
	}

	return 0;
}
#include<iostream>
#include<cstdio>

using namespace std;

int n,K;
//int dp[104][1004]={0};
long long dp[2][1004]={0};

int main()
{
	int i,j,k;
	cin>>n>>K;
	for(i=0;i<=n;i++)
		dp[1][i]=1;
	for(i=2;i<=K;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(k=0;k<=n;k=k+i)
				if(j-k>=0)
				dp[i%2][j]+=dp[(i-1)%2][j-k];
		}
		;
		memset(dp[(i-1)%2],0,sizeof(dp[(i-1)%2]));
	}
	cout<<dp[K%2][n]<<endl;
	return 0; 
}
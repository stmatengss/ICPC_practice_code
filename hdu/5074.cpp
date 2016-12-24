////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-10 16:22:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5074
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1840KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int mp[54][54];
int dp[104][54];
int n,m;
int num[104];
int res;

int main()
{
	int i,j,k;
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		res=-1;
		cin>>n>>m;
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		for(i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(i=2;i<=n;i++)
		{
			if(num[i]==-1)
			{
				if(num[i-1]==-1)
				{
					for(j=1;j<=m;j++)
					{
						for(k=1;k<=m;k++)
						{
							dp[i][j]=max(dp[i][j],dp[i-1][k]+mp[k][j]);
						}
					}
				}
				else
				{
					for(j=1;j<=m;j++)
					{
						dp[i][j]=max(dp[i][j],dp[i-1][num[i-1]]+mp[num[i-1]][j]);
					}
				}
			}
			else
			{
				if(num[i-1]==-1)
				{
					for(j=1;j<=m;j++)
					{
						dp[i][num[i]]=max(dp[i][num[i]],dp[i-1][j]+mp[j][num[i]]);
					}
				}
				else
				{
					dp[i][num[i]]=dp[i-1][num[i-1]]+mp[num[i-1]][num[i]];
				}
			}
		}
		for(i=1;i<=m;i++)
			res=max(res,dp[n][i]);
		cout<<res<<endl;
	}
}
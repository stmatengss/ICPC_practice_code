////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-04 12:10:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
int dp[1004];
int num[1004];
int maxnum;

int main()
{
	int i,j;
	while(cin>>n)
	{
		maxnum=-1;
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		dp[1]=num[1];
		for(i=2;i<=n;i++)
		{
			dp[i]=num[i];
			for(j=1;j<=i-1;j++)
			{
				if(num[i]>num[j]&&dp[i]<dp[j]+num[i])
				{
					dp[i]=dp[j]+num[i];
				}
			}
			maxnum=max(dp[i],maxnum);
		}
		cout<<maxnum<<endl;

	}
	return 0;
}

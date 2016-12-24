#include<iostream>
#include<cstdio>

int dp[1000000];
using namespace std;

int main()
{
	int n;
	cin>>n;
	//int temp1=1,temp2=1,temp;
	int i;
	dp[0]=1;
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		if(i&1)
		{
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=(dp[i/2]+dp[i-1])%1000000000;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int t,a,s,b;
int temp;
int num[1004]={0};
int dp[2][100004]={0};
int counter=0;

int main()
{
	cin>>t>>a>>s>>b;
	{
	int i,j,k;
	counter=0;
	memset(num,0,sizeof(num));
	for(i=1;i<=a;i++)
	{
		cin>>temp;
		num[temp]++;
	}
	memset(dp,0,sizeof(dp));
	//dp[1][1]=0;
	for(i=0;i<=num[1];i++) 
		dp[1][i]=1;
	for(i=2;i<=t;i++)
	{
		
		for(j=0;j<=b;j++)
		{
			for(k=0;k<=num[i];k++)
			{
				if(j-k>=0)
				{
					dp[i%2][j]=(dp[i%2][j]+dp[(i-1)%2][j-k])%1000000;
				}
				
			}
			//dp[i%2][j]
		}
		fill(dp[(i-1)%2],dp[(i-1)%2]+b,0);
	}
	for(i=s;i<=b;i++)
		counter=(counter+dp[t%2][i])%1000000;
	cout<<counter<<endl; 
	}
	return 0;
}
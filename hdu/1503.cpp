////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-16 18:56:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1503
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:3760KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
string a,b;

int main()
{
	int i,j;
	while(cin>>a>>b)
	{
		int dp[104][104];
		string res[104][104];
		for(i=0;i<=a.length();i++)
		{
			for(j=0;j<=b.length();j++)
			{
				if(i==0||j==0)
				{
					if(i==0)
					{
						dp[i][j]=j;
						res[i][j]=b.substr(0,j);
					}
					else
					{
						dp[i][j]=i;
						res[i][j]=a.substr(0,i);
					}
				}
				else if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					res[i][j]=res[i-1][j-1]+a[i-1];
				}
				else
				{
					if(dp[i][j-1]>dp[i-1][j])
					{
						dp[i][j]=dp[i-1][j]+1;
						res[i][j]=res[i-1][j]+a[i-1];
					}
					else
					{
						dp[i][j]=dp[i][j-1]+1;
						res[i][j]=res[i][j-1]+b[j-1];
					}
				}
			}
		}
//		cout<<dp[a.length()][b.length()]<<endl;
		cout<<res[a.length()][b.length()]<<endl;
	}
	return 0;
}
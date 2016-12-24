#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=1500;
int dp[2][maxn];
string s1,s2;

int main()
{
	int i,j;
	while(cin>>s1>>s2)
	{
		memset(dp,0,sizeof(dp));
//		cout<<s1<<' '<<s2<<endl;
		for(i=1;i<=s1.length();i++)
		{
			for(j=1;j<=s2.length();j++)
			{
				if(s1[i-1]==s2[j-1])
				{
					dp[i&1][j]=dp[(i-1)&1][j-1]+1;
				}
				else
				{
					dp[i&1][j]=max(max(dp[(i-1)&1][j],dp[i&1][j-1]),dp[(i-1)&1][j-1]);
				}
			}
		}
		cout<<dp[s1.length()&1][s2.length()]<<endl;
	}
	return 0;
}
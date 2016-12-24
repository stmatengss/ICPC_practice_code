////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-04 12:27:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:4552KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
string s1,s2;
int dp[5004][5004];

int main()
{
	int i,j;
	while(cin>>s1>>s2)
	{
		for(i=0;i<s1.length();i++)
			for(j=0;j<s2.length();j++)
			{
				dp[i+1][j+1]=dp[i][j];
				if(s1[i]==s2[j])
				{
					dp[i+1][j+1]+=1;
				}
				dp[i+1][j+1]=max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
			}
		cout<<dp[s1.length()][s2.length()]<<endl;
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int dp[104][104];
string s1,s2;
int len1,len2,n;
int table[6][6]={
	{0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1},
};
map<char,int> dict;
int sum;

int find(char x)
{
	if(x=='A')return 1;
	if(x=='C')return 2;
	if(x=='G')return 3;
	if(x=='T')return 4;
}

int main()
{
	int t;
	cin>>t;
	int i,j;
	while(t--)
	{
		s1.clear();
		s2.clear();
		memset(dp,0,sizeof(dp));
		sum=0;
		cin>>len1>>s1;
		cin>>len2>>s2;
		//if(len1<len2)swap(s1,s2);
		//n=abs(len1-len2);
		for(i=1;i<=len1;i++)
		{
			dp[i][0]+=dp[i-1][0]+table[find(s1.at(i-1))][5];
		}
		for(i=1;i<=len2;i++)
		{
			dp[0][i]+=dp[0][i-1]+table[find(s2.at(i-1))][5];
		}
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
			{
				dp[i][j]=max(dp[i-1][j-1]+table[find(s1.at(i-1))][find(s2.at(j-1))],
				max(dp[i-1][j]+table[find(s1.at(i-1))][5],
				dp[i][j-1]+table[5][find(s2.at(j-1))]));
			}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}
/*
2 
7 AGTGATG 
5 GTTAG 
7 AGCTATT 
9 AGCTTTAAA 
*/
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 15:13:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2845
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

int n,m;
int col[200004],row[200004];
int num;

int main()
{
	int i,j;
	while(cin>>n>>m)
	{
		fill(row,row+n+1,0);
		for(i=1;i<=n;i++)
		{
			fill(col,col+m+1,0);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&num);
//				dp[i%2][j][0]=max(dp[i%2][j-1][1],dp[(i-1)%2][j][1]);
//				dp[i%2][j][1]=max(dp[i%2][j-1][0],dp[(i-1)%2][j][0])+num;
				if(j==1)col[j]=num;
				if(j>=2)col[j]=max(col[j-2]+num,col[j-1]);
			}
			if(i==1)row[1]=col[m];
			if(i>=2)row[i]=max(row[i-2]+col[m],row[i-1]);
		}
		cout<<row[n]<<endl;
	}
	return 0;
}
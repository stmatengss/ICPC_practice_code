////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 15:13:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2830
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:5536KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

char num[1004];
int len[1004][1004];
int res;
int n,m;
int now;
int wid;

int main()
{
	int i,j;
	while(cin>>n>>m)
	{
		res=-1;
		memset(len,0,sizeof(len));
		gets(num);
		for(i=1;i<=n;i++)
		{
			gets(num);
			for(j=1;j<=m;j++)
			{
				if(num[j-1]=='1')
				{
					len[i][j]=len[i-1][j]+1;
				}
				else
				{
					len[i][j]=0;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			sort(len[i]+1,len[i]+m+1);
			for(j=1;j<=m;j++)
			{
				res=max(res,len[i][j]*(m+1-j));
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
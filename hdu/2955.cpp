////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 15:14:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2955
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

double p[104];
int v[104];
double pi;
int n;
int sum;
double dp[10004];
int res;

int main()
{
	int t,i,j;
//	int n;
	cin>>t;
	while(t--)
	{
//		cin>>pi>>n;
		scanf("%lf%d",&pi,&n);
		pi=1-pi;
		memset(dp,0,sizeof(dp));
		res=-1;
		sum=0;
		for(i=1;i<=n;i++)
		{
//			cin>>v[i]>>p[i];
			scanf("%d%lf",&v[i],&p[i]);
			p[i]=1-p[i];
			sum+=v[i];
		}
		dp[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=sum;j>=v[i];j--)
			{
				dp[j]=max(dp[j-v[i]]*p[i],dp[j]);
			}
		}
//		cout<<pi<<" "<<sum<<endl;.
		for(i=sum;i>=0;i--)
		{
			if(dp[i]>pi)
			{
				cout<<i<<endl;
				break;
			}
		}
//		cout<<res<<endl;
	}
	return 0;
}
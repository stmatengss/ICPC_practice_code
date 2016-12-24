////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-10 16:26:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5073
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:2200KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,k,m;
double res,s1,s2,s3;
long long num[50004];
double sum;

int main()
{
	int i,j,k;
	int t;
	cin>>t;
	while(t--)
	{
		sum=0;
		s1=0,s2=0,s3=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&num[i]);
		}
		sort(num,num+n);
		m=n-k;
		res=0.0;
		if(m!=0)
		for(i=0;i<n;i++)
		{
			if(i<m)
			{
				sum+=num[i];
				s1+=num[i]*num[i];
			}
			else
			{
				s1+=(num[i]*num[i]-num[i-m]*num[i-m]);
				sum+=(num[i]-num[i-m]);
				res=min(res,s1-(sum/m)*sum);
			}
			if(i==m-1)
			{
				res=s1-(sum/m)*sum;
			}
		}
		printf("%.11lf\n",res);
	}
	return 0;
}
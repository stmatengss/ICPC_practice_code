////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-25 23:12:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5280
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int maxn=1004;

int num[maxn];
int n,k;

int main()
{
	int t;
	int i,j;
	long long sum,temp,res=-10000000000000;
	cin>>t;
	while(t--)
	{
		res=-10000000000000;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>num[i];
		}
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				temp=num[j];
				if(i==j)
				{
					temp=k;
				}
				sum+=temp;
				if(sum>res)
				{
					res=sum;
				}
				else if(sum<0)
				{
					sum=0;
				}
			}
//			res=max(res,sum);
		}
		cout<<res<<endl;
   	}
}

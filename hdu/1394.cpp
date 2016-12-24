////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-05 16:30:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1784KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int sum[5004];
int num[5004];
int n;
int res,ans;

int main()
{
	int i,j,k;
	while(~scanf("%d",&n))
	{
		memset(sum,0,sizeof(sum));
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(num[j]<num[i])
					ans++;
			}
		}
		res=ans;
		for(i=0;i<n;i++)
		{
			res=res-num[i]+(n-num[i]-1);
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
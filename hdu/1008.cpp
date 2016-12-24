////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-08 00:27:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int i,j;
	int n;
	int pro,now;
	int sum=0;
	while(cin>>n)
	{
		if(n==0)
			break;
		pro=0;
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>now;
			if(now>pro)
			{
				sum+=(now-pro)*6+5;
			}
			else if(now==pro)
			{
				sum+=5;
			}
			else if(now<pro)
			{
				sum+=(pro-now)*4+5;
			}
			pro=now;
		}
		cout<<sum<<endl;
	}
	return 0;
}
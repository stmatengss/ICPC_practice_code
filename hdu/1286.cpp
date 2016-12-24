////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-14 14:12:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1744KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int num;
vector<int>prime;
int isprime[32768];

void table()
{
	int i,j;
	for(i=2;i<=32767;i++)
	{
		if(isprime[i]==0)
		{
			prime.push_back(i);
			for(j=2*i;j<=32767;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}


int main()
{
	int res;
	int t;
	int st;
	int i,j;
	table();
	cin>>t;
	while(t--)
	{
		cin>>num;
		if(isprime[num]==0)
		{
			printf("%d\n",num-1);
		}
		else
		{
			res=num;
			for(i=0;i<prime.size();i++)
			{
				if(prime[i]==num)
				{
					res*=(prime[i]-1);
					res/=(prime[i]);
					break;
				}
				st=1;
				while(num%prime[i]==0)
				{
					if(st)
					{
						st=0;
						res*=(prime[i]-1);
						res/=(prime[i]);
					}
					if(prime[i]==num)
					{
						break;
					}
					num/=prime[i];
				}
			}
			printf("%d\n",res);
		}
		
	}
	return 0;
}
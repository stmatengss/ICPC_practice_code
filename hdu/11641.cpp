////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-14 11:33:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1916KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int>prime;
int isprime[65537];

void table()
{
	int i,j;
	for(i=2;i<=65535;i++)
	{
		if(isprime[i]==0)
		{
			prime.push_back(i);
			for(j=2*i;j<=65535;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}

int main()
{
	int num;
	int i,j;
	table();
	while(cin>>num)
	{
		for(i=0;i<prime.size();i++)
		{
			if(prime[i]==num)
			{
				cout<<num<<endl;
				break;
			}
			while(num%prime[i]==0)
			{
				if(prime[i]==num)
				{
					cout<<num<<endl;
					break;
				}
				else
					cout<<prime[i]<<"*";
				num/=prime[i];
			}
		}
	}
	return 0;
}
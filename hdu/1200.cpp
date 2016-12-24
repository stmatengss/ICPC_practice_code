////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-17 17:53:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

string s;
int n,m;
int tmp;

int main()
{
	int i,j;
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		cin>>s;
		m=s.length()/n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				tmp=j*n;
				if(j&1)
				{
					tmp+=(n-1-i);
				}
				else
				{
					tmp+=i;
				}
				cout<<s[tmp];
			}
		}
		cout<<endl;
	}
	return 0;
}
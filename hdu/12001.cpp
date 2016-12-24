////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-17 17:55:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

string s;
int n,m;

int main()
{
	int i,j;
	while(cin>>n&&n!=0)
	{
		cin>>s;
		m=s.length()/n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(j&1)
					cout<<s[j*n+n-1-i];
				else
					cout<<s[j*n+i];
			}
		}
		cout<<endl;
	}
	return 0;
}
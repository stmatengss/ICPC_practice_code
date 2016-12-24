////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-16 21:25:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1290
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;
ll tab1[1004];
ll tab2[1004];

int main()
{
	ll n;
	int i;
	tab1[1]=2;
	for(i=2;i<=1000;i++)
	{
		tab1[i]=tab1[i-1]+i;
	}
	tab2[1]=2;
	for(i=2;i<=1000;i++)
	{
		tab2[i]=tab2[i-1]+tab1[i-1];
	}
	while(cin>>n)
	{
		cout<<tab2[n]<<endl;
	}
	return 0;
}
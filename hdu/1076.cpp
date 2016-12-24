////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-01 00:25:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

int year,res,no,counter;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		counter=0;
		cin>>year>>no;
		year--;
		while(counter<no)
		{
			year++;
			if((year%4==0&&year%100!=0)||year%400==0)counter++;
		}
		cout<<(year)<<endl;
	}
	
	return 0;
}
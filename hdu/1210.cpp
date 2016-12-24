////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-07 15:15:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1210
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
using namespace std;
int counter;
int begin;

int main()
{
	int n;
	while(cin>>n)
	{
		begin=1;
		counter=0;
		while(1)
		{
		if(begin<=n)
		{
			begin=begin*2;
		}
		else
		{
			begin=(begin-n)*2-1;
		}
		counter++;
		if(begin==1)break;
	    }
	    cout<<counter<<endl;
	}
}
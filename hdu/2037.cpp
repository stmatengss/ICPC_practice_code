////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-11-11 00:11:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

typedef struct seg{
	int b;
	int e;
};

bool cmp(seg a,seg b)
{
	return a.e<b.e;
}

int n,i,j;
seg s[10000];
int pre;
int counter;

int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		for(i=1;i<=n;i++)
		cin>>s[i].b>>s[i].e;
		sort(s,s+n,cmp);
        counter=0;  
        pre=s[1].e;
		for(i=2;i<=n;i++)
		{
			if(s[i].b>=pre)
			{
				pre=s[i].e;
				counter++;
			}
		}
		cout<<counter+1<<endl;		
	}
	return 0;
}
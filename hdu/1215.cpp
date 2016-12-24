////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-14 13:00:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:3552KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

//vector<int>prime;
int tab[500004];

void table()
{
	int i,j;
//	for(i=1;i<=500000;i++)
//		tab[i]=0;
	for(i=1;i<=500000;i++)
	{
		for(j=2*i;j<=500000;j+=i)
		{
			tab[j]+=i;
		}
	}
}

int main()
{
	int num;
	int i,j;
	int res;
	int t;
	table();
 	cin>>t;
	while(t--)
	{
		scanf("%d",&num);
		printf("%d\n",tab[num]);
//		res=1;
//		for(i=2;i<=sqrt(num);i++)
//		{
//			if(num%i==0)
//			{
//				res+=i;
//				if(num/i!=i)
//				{
//					res+=num/i;
//				}
//			}
//		}
//		cout<<tab[num]<<endl;
	}
	return 0;
}
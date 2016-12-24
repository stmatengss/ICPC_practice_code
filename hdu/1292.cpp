////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-17 10:41:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1292
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

long long tab[30][30];
long long res[30];

int main()
{
	int i,j,k;
	int n;
//	for(i=1;i<=25;i++)
//		tab[0][i]=1;
	tab[0][0]=1;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=i;j++)
		{
			tab[i][j]=tab[i-1][j-1];
			if(j<i)tab[i][j]+=tab[i-1][j]*j;
			res[i]+=tab[i][j];
		}
	}
	int t;
	cin>>t;
	while(t--)
 	{
 		cin>>n;
  		cout<<res[n]<<endl;
 	}
	return 0;
}
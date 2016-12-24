////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-14 11:41:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int num,res;
	while(cin>>num)
	{
		res=1;
		if(num==0)
			break;
		while(num)
		{
			if(num&1)
			{
				cout<<res<<endl;
				break;
			}
			res*=2;
			num/=2;
		}
	}
	return 0;
}
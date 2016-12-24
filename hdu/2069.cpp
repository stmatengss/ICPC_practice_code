////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:06:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>

using namespace std;

int n;

int main()
{
	int i,j,k,l;
	long long counter=0;
	while(cin>>n)
	{
		counter=0;
		for(i=0;i*50<=n;i++)
		{
			for(j=0;i*50+j*25<=n;j++)
			{
				for(k=0;i*50+j*25+k*10<=n;k++)
				{
					for(l=0;i*50+j*25+k*10+l*5<=n;l++)
					{
						if(i+j+k+l+(n-i*50-j*25-k*10-l*5)<=100)
							counter++;
					}
				}
			}
		}
		cout<<counter<<endl;
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 15:26:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>v;

int main()
{
	int i,j;
	int st,num;
	int n,pro,res;
	while(cin>>n)
	{
		res=0;
		st=0;
		v.clear();
//		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			cin>>num;
			st=1;
			for(j=0;j<v.size();j++)
			{
				if(num<v[j])
				{
					v[j]=num;
					st=0;
					break;
				}
			}
			if(st)
			{
				v.push_back(num);
			}
		}
		cout<<v.size()<<endl;
	}
	return 0;
}
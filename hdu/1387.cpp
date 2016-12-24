////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:07:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1387
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:3376KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

string s;

int main()
{
	int t;
	int n;
	int i,j,k;
	int in;
	int counter=0;
	while(cin>>t)
	{
		counter++;
		if(t==0)break;
		map<int,int>num;
		queue<int>team[1004];
		queue<int>rank;
		int used[1004]={0};
		for(i=1;i<=t;i++)
		{
			cin>>n;
			for(j=1;j<=n;j++)
			{
				cin>>in;
				num[in]=i;
			}
		}
		cout<<"Scenario #"<<counter<<endl;
		while(1)
		{
			s="";
			cin>>s;
			if(s[0]=='S')
			{
				cout<<endl;
				break;
			}
			else if(s[0]=='E')
			{
				cin>>in;
				if(used[num[in]])
				{
					team[num[in]].push(in);
				}
				else
				{
					team[num[in]].push(in);
					rank.push(num[in]);
					used[num[in]]=1;
				}
			}
			else if(s[0]=='D')
			{
				in=rank.front();
				cout<<(team[in].front())<<endl;
				team[in].pop();
				if(team[in].empty())
				{
					rank.pop();
					used[in]=0;
				}
			}
		}
	}
	return 0;
}
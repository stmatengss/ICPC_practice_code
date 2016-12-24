////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 09:57:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4288
////Problem Title: 
////Run result: Accept
////Run time:5475MS
////Run memory:2796KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

char order[5];
int num;
int n;
vector<int>s;
vector<int>::iterator it;
long long res=0;
int pos;

int main()
{
	int i,j;
	while(cin>>n)
	{
		s.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%s",order);
			if(order[0]=='a')
			{
				scanf("%d",&num);
				it=lower_bound(s.begin(),s.end(),num);
				s.insert(it,num);
			}
			else if(order[0]=='d')
			{
				scanf("%d",&num);
				it=lower_bound(s.begin(),s.end(),num);
				s.erase(it);
			}
			else if(order[0]=='s')
			{
				res=0;
				if(!s.empty())
				for(j=2;j<s.size();j+=5)
				{
						res+=s[j];
				}
//				cout<<res<<endl;
				printf("%I64d\n",res);
			}
		}
	}
	return 0;
}
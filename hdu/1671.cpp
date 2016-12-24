////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:04:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:2296KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<string>s;
string in;
bool status;

int main()
{
	int i,j,k;
	int t;
	cin>>t;
	while(t--)
	{
		status=true;
		s.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			in="";
			cin>>in;
			s.push_back(in);
		}
		sort(s.begin(),s.end());
		for(i=1;i<n;i++)
		{
//			if(s[i]==s[i-1])continue;
			if(s[i].length()>s[i-1].length())
			{
				if(s[i].substr(0,s[i-1].length())==s[i-1])
				{
					status=false;
					break;
				}
			}
		}
		if(status)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 23:24:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1744KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
string st[4]={"st","nd","rd"};

vector<ll>v;

void table()
{
	int i,j,k,l;
	ll num,numa,numb,numc,numd;
	for(i=0;i<=30;i++)
	{
		if(i==0)numa=1;
		else numa*=2;
		for(j=0;j<=19;j++)
		{
			if(j==0)numb=1;
			else numb*=3;
			if(numa*numb>2000000000)
				break;
			for(k=0;k<=13;k++)
			{
				if(k==0)numc=1;
				else
				numc*=5;
				if(numa*numb*numc>2000000000)
					break;
				for(l=0;l<=11;l++)
				{
					if(l==0)numd=1;
					else numd*=7;
					num=numa*numb*numc*numd;
					if(num>2000000000)
						break;
					v.push_back(num);
				}
			}
		}
	}
}

void dfs(int r)
{

}

int main()
{
	int num;
	table();
	sort(v.begin(),v.end());
	while(cin>>num)
	{
		if(num==0)
			break;
		if(num%10<=3&&num%10>=1&&num%100/10!=1)
			cout<<"The "<<num<<(st[(num-1)%10])<<" humble number is "<<v[num-1]<<"."<<endl;
		else
			cout<<"The "<<num<<"th humble number is "<<v[num-1]<<"."<<endl;
	}
	return 0;
}
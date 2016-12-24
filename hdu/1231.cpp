////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-13 15:14:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:920MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
int n;
ll sum,res,num;
int pro,nxt,before;
int bg,ed;
int st;

int main()
{
	int i;
	while(cin>>n)
	{
		if(n==0)
			break;
		pro=1;
		res=-1000000;
		sum=0;
		st=0;
	 	for(i=1;i<=n;i++)
		{
			cin>>num;
			if(i==1)
				pro=num,bg=num;
			if(i==n)
				ed=num;
			sum+=num;
			if(st==1)
			{
				pro=num;
				st=0;
			}
			if(sum>res)
			{
				res=sum;
				before=pro;
				nxt=num;
			}
			if(sum<0)
			{
				sum=0;
				st=1;
			}
		}
		if(res<0)
		{
			cout<<"0 "<<bg<<" "<<ed<<endl;
		}
		else
		{
			cout<<res<<" "<<before<<" "<<nxt<<endl;
		}
	}
	
	return 0;
}
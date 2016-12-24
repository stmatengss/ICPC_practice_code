////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 09:59:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4296
////Problem Title: 
////Run result: Accept
////Run time:530MS
////Run memory:3592KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct point{
	int w;
	int s;
	point(int w,int s):w(w),s(s){
	}
	int operator<(const point &a)const{
		return (w+s)<(a.w+a.s);
	}
};

vector<point>v;
int n;

int main()
{
	int i,j;
	int x,y;
	long long res;
	long long sum;
	while(cin>>n)
	{
		v.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			v.push_back(point(x,y));
		}
		sort(v.begin(),v.end());
		sum=0;
		res=-10000000000000L;
		for(i=0;i<n;i++)
		{
			if((sum-v[i].s)>res)
				res=sum-v[i].s;
			sum+=v[i].w;
		}
		cout<<res<<endl;
	}
	return 0;
}
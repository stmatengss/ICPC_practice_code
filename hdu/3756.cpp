////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-06 19:52:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3756
////Problem Title: 
////Run result: Accept
////Run time:1045MS
////Run memory:1756KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

struct point{
	double r,h;
};

point p[10004];
double left_,right_,mid,midmid;
double ans1,ans2;
int n;

double getr(double h)
{
	int i;
	double res=-1;
	double r;
	for(i=1;i<=n;i++)
	{
		r=h*(p[i].r)/(h-p[i].h);
		res=max(r,res);
	}
	return res;
}

int main()
{
	int i,j,k;
	double x,y,z;
	int t;
//	cin>>t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		left_=-1;
		for(i=1;i<=n;i++)
		{
//			cin>>x>>y>>z;
			scanf("%lf%lf%lf",&x,&y,&z);
			p[i].r=sqrt(x*x+y*y);
			p[i].h=z;
			left_=max(z,left_);
		}
		right_=1e4;
		while(right_-left_>=1e-4)
		{
			mid=(left_+right_)/2;
			midmid=(mid+right_)/2;
			ans1=getr(mid);
			ans2=getr(midmid);
			if(ans1*ans1*mid>ans2*ans2*midmid)
			{
				left_=mid;
			}
			else
			{
				right_=midmid;
			}
		}
		printf("%.3lf %.3lf\n",mid,ans1);
	}
	
	return 0;
}

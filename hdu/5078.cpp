////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-10 16:25:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5078
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

//struct point{
//	int t;
//	int x,int y;
//};
//
//int cmp(point a,point b)
//{
//	return a.t<b.t;
//}

int n;
//point h[1002];
double x,y,t1,t2,xx,yy;
double res,res2;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		t1=0;
		res=-1;
		res2=0;
		scanf("%lf%lf%lf",&t1,&xx,&yy);
		for(int i=1;i<n;i++)
		{
			scanf("%lf%lf%lf",&t2,&x,&y);
			res=max(res,sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))/(t2-t1));
//			res2+=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))/(t2-t1);
			t1=t2;
			xx=x;
			yy=y;
		}
		printf("%.10lf\n",res);
//		printf("%.10lf\n",res2);
	}
	return 0;
}
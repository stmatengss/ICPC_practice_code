////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-14 10:33:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

//int i,j,k;
const int MAXN=5;
const double EPS=1e-12;

inline int solve(double a[][MAXN],bool l[],double ans[],
const int& n)
{
	int res=0,r=0;
	for(int i=0;i<n;i++)
		l[i]=false;
	for(int i=0;i<n;i++)
	{
		for(int j=r;j<n;j++)
			if(fabs(a[j][i])>EPS)
			{
				for(int k=i;k<=n;k++)
					swap(a[j][k],a[r][k]);
				break;
			}
		if(fabs(a[r][i])<EPS)
		{
			res++;
			continue;
		}
		for(int j=0;j<n;j++)
			if(j!=r&&fabs(a[j][i])>EPS)
			{
				double tmp=a[j][i]/a[r][i];
				for(int k=i;k<=n;k++)
				{
					a[j][k]-=tmp*a[r][k];
				}
			}
		l[i]=true,r++;
	}
	for(int i=0;i<n;i++)
	{
		if(l[i])
		for(int j=0;j<n;j++)
		{
			if(fabs(a[j][i])>0)
				ans[i]=a[j][n]/a[j][i];
		}
	}
	return res;
}

int main()
{
	int t;
	double a,b,c;
	double k,bb;
	double ub,lb;
	double x[4],y[4];
//	double ans[MAXN];
//	bool l[MAXN];
//	double a[MAXN][MAXN];
	int n;
 	cin>>t;
// 	n=3;
	while(t--)
	{
		cin>>x[2]>>y[2];
		cin>>x[1]>>y[1];
		cin>>x[3]>>y[3];
		a=(y[1]-y[2])/((x[1]-x[2])*(x[1]-x[2]));
		b=-2.0*a*x[2];
		c=y[2]-a*x[2]*x[2]-b*x[2];
		k=(y[3]-y[1])/(x[3]-x[1]);
		bb=y[1]-k*x[1];
		ub=1.0/3*a*x[3]*x[3]*x[3]+0.5*(b-k)*x[3]*x[3]+(c-bb)*x[3];
		lb=1.0/3*a*x[1]*x[1]*x[1]+0.5*(b-k)*x[1]*x[1]+(c-bb)*x[1];
//		solve(a,l,ans,n);
//		for(int i=0;i<n;i++)
////		if(l[i])
//			cout<<ans[i]<<' ';
		printf("%.2lf\n",ub-lb);
	}
	
	return 0;
}
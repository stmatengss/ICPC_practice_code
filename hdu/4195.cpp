////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-01 13:06:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4195
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

const  double trans=57.29577951;
const  double EPS=1e-5;
double x[4],y[4];
double r[4];
double delta[4];
double ka,num;
int st;

double dis(double x,double y,double xx,double yy)
{
	return sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
}

bool zero(double n){
    return n < EPS && n > -EPS;
}

bool cmp(double a)
{
	return zero(a - (int) (a + 0.5));
//	double b;
//	if (fabs(a-((int)a)) < EPS)
//		return true;
//	return false;
//	b=(int)(a+0.5);
//	if(a<b+EPS&&a>b-EPS)
//		return true;
//	return false;
}

int main()
{
	int i,j;
//	cout<<"Test:"<<cmp(1.0000)<<endl;
	while(scanf("%lf %lf",&x[0],&y[0]))
	{
		scanf("%lf %lf",&x[1],&y[1]);
		scanf("%lf %lf",&x[2],&y[2]);
		r[0]=dis(x[0],y[0],x[1],y[1]);
		r[1]=dis(x[1],y[1],x[2],y[2]);
		r[2]=dis(x[2],y[2],x[0],y[0]);
		delta[0]=acos((r[0]*r[0]+r[1]*r[1]-r[2]*r[2])/(2*r[0]*r[1]))*trans;
		delta[1]=acos((r[1]*r[1]+r[2]*r[2]-r[0]*r[0])/(2*r[1]*r[2]))*trans;
		delta[2]=acos((r[0]*r[0]+r[2]*r[2]-r[1]*r[1])/(2*r[0]*r[2]))*trans;
//		for(i=0;i<3;i++)
//			cout<<delta[i]<<endl;
		for(i=3;i<=1000;i++)
		{
			st=0;
			ka=180.0/double(i);
			for(j=0;j<3;j++)
			{
				num=delta[j]/ka;
//				cout<<num<<endl;
				if(cmp(num))
				{
//					cout<<"OK"<<num<<endl;
					st++;
				}
			}
//			cout<<st<<endl;
			if(st==3)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
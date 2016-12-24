////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 16:40:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1724
////Problem Title: 
////Run result: Accept
////Run time:577MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double a,b,ab;

double cal(double x)
{
    return sqrt((ab-b*b*x*x)/a/a);
}

double simpson(double l,double r)
{
    return (r-l)*(cal(l)+4.0*cal((l+r)/2.0)+cal(r))/6.0;
}

double div(double l,double r,double eps,double sum)
{
    double mid=(l+r)/2.0;
    double suml,sumr;
    suml=simpson(l,mid);
    sumr=simpson(mid,r);
    if(fabs(sum-(suml+sumr))<eps)return sum;
    return div(l,mid,eps/2,suml)+div(mid,r,eps/2,sumr);
}

int main()
{
    double le,ri;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ab=a*a*b*b;
        cin>>le>>ri;
        printf("%.3lf\n",div(le,ri,1e-6,simpson(le,ri))*2);
    }
    return 0;
}

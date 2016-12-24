////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-23 15:21:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3400
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1652KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps=1e-7;
const double mind=1e-9;
double x[4],y[4];
double p,q,r;
double ab,cd;

double dist(double xx,double yy,double xxx,double yyy)
{
    return sqrt(mind+(xx-xxx)*(xx-xxx)+(yy-yyy)*(yy-yyy));
}

double fun2(double pi,double pj)
{
    double xxx,yyy,xx,yy;
    xx=x[1]*pi+x[0]*(1.0-pi);
    yy=y[1]*pi+y[0]*(1.0-pi);
    xxx=x[3]*pj+x[2]*(1.0-pj);
    yyy=y[3]*pj+y[2]*(1.0-pj);
    return ab*pi+dist(xx,yy,xxx,yyy)/r+cd*(1-pj);
}

double fun(double pi)
{
    double le,ri,mid,midmid;
    le=0,ri=1.0;
    while(ri-le>eps)
    {
        mid=(le+ri)/2.0;
        midmid=(mid+ri)/2.0;
        if(fun2(pi,mid)<fun2(pi,midmid))ri=midmid+mind;
        else le=mid-mind;
    }
    return fun2(pi,mid);
}

int main()
{
    int t;
    int i,j;
    double le,ri,mid,midmid;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<=3;i++)
            cin>>x[i]>>y[i];
        cin>>p>>q>>r;
        ab=dist(x[0],y[0],x[1],y[1])/p;
        cd=dist(x[2],y[2],x[3],y[3])/q;
        le=0,ri=1.0;
        while(ri-le>eps)
        {
            mid=(le+ri)/2.0;
            midmid=(mid+ri)/2.0;
            if(fun(mid)<fun(midmid))ri=midmid+mind;
            else le=mid-mind;
        }
        printf("%.2lf\n",fun(mid));
    }
//    cout << "Hello world!" << endl;
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 17:32:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5017
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1636KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double inf=1e4;
double a,b,c,d,e,f;

double find(double a,double b,double c)
{
    double tmp=b*b-4*a*c;
    if(tmp<0)return inf;
    if(b<0) return (-b-sqrt(tmp))/a/2;
    else return (-b+sqrt(tmp))/a/2;
}

double cal(double x,double y)
{
    double z=find(c,d*y+e*x,a*x*x+b*y*y+f*x*y-1);
    return x*x+y*y+z*z;
}

double fun(double x)
{
    double le=-inf,ri=inf;
    double mid,midmid;
    for(int i=1;i<=50;i++)
    {
        mid=(le+ri)/2;
        midmid=(mid+ri)/2;
        if(cal(x,mid)<cal(x,midmid))ri=midmid;
        else le=mid;
    }
    return cal(x,le);
}

double fun()
{
    double le=-inf,ri=inf;
    double mid,midmid;
    for(int i=1;i<=50;i++)
    {
        mid=(le+ri)/2;
        midmid=(mid+ri)/2;
        if(fun(mid)<fun(midmid))ri=midmid;
        else le=mid;
    }
    return fun(le);
}

int main()
{
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        printf("%.7lf\n",sqrt(fun()));
    }
//    cout << "Hello world!" << endl;
    return 0;
}

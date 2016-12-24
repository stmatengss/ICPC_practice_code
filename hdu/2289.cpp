////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 14:19:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2289
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double eps=1e-6;
const double pi=acos(-1.0);
double R,r,H,h,v,V,k;

double cal(double x)
{
    double rr=r+x*k;
    return 1.0*pi*(rr*rr+r*r+r*rr)*x/3.0;
}

int main()
{
    double le,ri,mid;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>R>>H>>v;
        k=((R-r)/H);
        le=0,ri=H;
        while(ri-le>1e-10)
        {
            mid=(le+ri)/2.0;
            if(cal(mid)<v)le=mid;
            else ri=mid;
        }
        printf("%.6lf\n",(le+ri)/2);
    }
    return 0;
}

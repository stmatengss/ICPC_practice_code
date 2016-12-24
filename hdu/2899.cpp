////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 12:12:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>

using namespace std;

double y;

double quick_pow(double x,int n)
{
    double res=1.0;
    while(n)
    {
        if(n&1)res*=x;
        x=x*x;
        n=n>>1;
    }
    return res;
}

double cal(double x)
{
    return 6.0*quick_pow(x,7)+8.0*quick_pow(x,6)
    +7.0*quick_pow(x,3)+5*quick_pow(x,2)-y*x;
}

int main()
{
    int i,j;
    double le,mid,ri,midmid;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>y;
        le=0,ri=100.0;
        for(i=1;i<=100;i++)
        {
            mid=(le+ri)/2;
            midmid=(mid+ri)/2;
            if(cal(mid)<cal(midmid))ri=midmid;
            else le=mid;
        }
        printf("%.4lf\n",cal(mid));
    }
    return 0;
}

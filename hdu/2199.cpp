////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 12:22:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2199
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>


using namespace std;

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
    return 8.0*quick_pow(x,4)+7.0*quick_pow(x,3)
    +2.0*quick_pow(x,2)+3*x+6;
}

int main()
{
    double lb,ub;
    double y;
    double le,mid,ri;
    int t;
    cin>>t;
    lb=cal(0);
    ub=cal(100.0);
    while(t--)
    {
        cin>>y;
        if(y<lb||y>ub)
        {
            cout<<"No solution!"<<endl;
        }
        else
        {
            le=0,ri=100.0;
            while(ri-le>1e-6)
            {
                mid=(le+ri)/2;
                if(cal(mid)>y)ri=mid;
                else le=mid;
            }
            printf("%.4lf\n",mid);
        }
    }
    return 0;
}

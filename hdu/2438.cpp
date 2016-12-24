////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-23 14:13:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2438
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1636KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi=acos(-1.0);
double  x, y, l, d;
double le,ri,mid,midmid;

double fun(double alp)
{
    return l*cos(alp)+d/sin(alp)-x/tan(alp);
}

int main()
{
    while(cin>>x>>y>>l>>d)
    {
        le=0,ri=pi/2.0;
        if(x<=d||y<=d)
        {
            cout<<"no"<<endl;
            continue;
        }
        while(ri-le>1e-7)
        {
            mid=le+(ri-le)/3.0;
            midmid=le+(ri-le)*2.0/3.0;
            if(fun(mid)<fun(midmid))le=mid;
            else ri=midmid;
        }
//        cout<<fun(mid)<<endl;
        if(fun(mid)>y)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

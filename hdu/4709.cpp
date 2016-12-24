////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-29 15:55:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4709
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1768KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps=1e-10;
const double maxone=1000000000.0;

struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};

double area(const point &ps,const point &pe,const point &po)
{
    return fabs((ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y))/2.0;
}

int n;
point p[104];

int main()
{
    int i,j,k;
    int t;
    bool st;
    double res,now;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>p[i].x>>p[i].y;
        }
        if(n<=2)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        res=maxone;
        st=false;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    now=area(p[i],p[j],p[k]);
                    if(now>eps)
                    {
                        st=true;
                        res=min(res,now);
                    }
                }
            }
        }
        if(st)
            printf("%.2lf\n",res);
        else
            cout<<"Impossible"<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
/*
1
4
-1.00 0.00
0.00 -3.00
2.00 0.00
2.00 2.00
4.00

*/
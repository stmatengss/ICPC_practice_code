#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

const double eps=1e-8;
using namespace std;

struct point{
    double x,y;
    point(){x=0,y=0;}
    point(double x,double y):x(x),y(y){}
};

point p[1004];
int n;
double X,Y;

double dis(const point &a,const point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//double pending(point o)
//{
//    double res=0;
//    for(int i=0;i<n;i++)
//        res+=dis(o,p[i]);
//    return res;
//}

double pending(point o)
{
    double res=10000000000;
    for(int i=0;i<n;i++)
        res=min(res,dis(o,p[i]));
    return res;
}

double fermentpoint()
{
    int i,j,k;
    point u=point(),v=point();
    double step=0;
    for(i=0;i<n;i++)
    {
//        step+=(fabs(p[i].x)+fabs(p[i].y));
        u.x+=p[i].x,u.y+=p[i].y;
    }
    step=1.0;
    u.x/=n,u.y/=n;
    while(step>eps)
    {
//        for(k=0;k<10,step/=2;k++)
            for(i=-1;i<=1;i++)
            {
                for(j=-1;j<=1;j++)
                {
                    v.x=u.x+step*(X/4)*i;
                    v.y=u.y+step*(Y/4)*j;
                    if(v.x>X||v.x<0||v.y>Y||v.y<0)continue;
                    if(pending(u)<pending(v))
                        u=v;
                }
            }
            step*=0.9;
    }
    printf("The safest point is (%.1lf, %.1lf).\n",u.x,u.y);
    return pending(u);
}

int main()
{
    int i,j,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>X>>Y>>n;
        for(i=0;i<n;i++)
            cin>>p[i].x>>p[i].y;
        fermentpoint();
//        printf("%.1f\n",fermentpoint());
    }
    return 0;
}

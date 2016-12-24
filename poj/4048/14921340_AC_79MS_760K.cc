#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>

const double eps=1e-8;

using namespace std;

struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point operator+ (const point &a)const
    {
        return point(x+a.x,y+a.y);
    }
    point operator- (const point &a)const
    {
        return point(x-a.x,y-a.y);
    }
    point operator* (const double &a)const
    {
        return point(x*a,y*a);
    }
    point operator/ (const double &a)const
    {
        return point(x/a,y/a);
    }
};

struct line
{
    point a,b;
    line(){}
    line(point a,point b):a(a),b(b){}
};

double det(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}

bool iscross(const line &a,const line &b)
{
    return (
    (max(a.a.x,a.b.x)>=min(b.a.x,b.b.x))&&
    (max(b.a.x,b.b.x)>=min(a.a.x,a.b.x))&&
    (max(a.a.y,a.b.y)>=min(b.a.y,b.b.y))&&
    (max(b.a.y,b.b.y)>=min(a.a.y,a.b.y))&&
    (det(a.a-b.a,b.b-b.a)*det(b.b-b.a,a.b-b.a)>=0.0)&&
    (det(b.a-a.a,a.b-a.a)*det(a.b-a.a,b.b-a.a)>=0.0)
    );

}

line check(const point &a,const point &b)
{
    double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    point tmp=(b-a)/len;
    return line(a,a+tmp*40004);
}

int n;
line l[1504];
point o;
line li;

int main()
{
    int t;
    int i,j;
    int res,counter;
//    cout<<iscross(line(point(0,0),point(1,2)),line(point(-1,2),point(1,2)))<<endl;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        res=-1;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
        }
        scanf("%lf%lf",&o.x,&o.y);
        for(i=0;i<n;i++)
        {
            counter=0;
            if(l[i].a.x!=o.x||l[i].a.y!=o.y)
            {
//                if(l[i].a.x>o.x&&l[i].a.y>o.y)li=line(o,l[i].a);
//                if(l[i].a.x<o.x&&l[i].a.y>o.y)li=line(o,l[i].a);
//                if(l[i].a.x>o.x&&l[i].a.y<o.y)li=line(o,l[i].a);
//                if(l[i].a.x<o.x&&l[i].a.y<o.y)li=line(o,l[i].a);
                li=check(o,l[i].a);
                for(j=0;j<n;j++)
                    if(iscross(li,l[j]))
                        counter++;
            }
            res=max(res,counter);
            counter=0;
            if(l[i].b.x!=o.x||l[i].b.y!=o.y)
            {
//                if(l[i].b.x>o.x&&l[i].b.y>o.y)li=line(o,l[i].b);
//                if(l[i].b.x<o.x&&l[i].b.y>o.y)li=line(o,l[i].b);
//                if(l[i].b.x>o.x&&l[i].b.y<o.y)li=line(o,l[i].b);
//                if(l[i].b.x<o.x&&l[i].b.y<o.y)li=line(o,l[i].b);
                li=check(o,l[i].b);
                for(j=0;j<n;j++)
                    if(iscross(li,l[j]))
                        counter++;
            }
            res=max(res,counter);
        }
        cout<<res<<endl;
    }
    return 0;
}

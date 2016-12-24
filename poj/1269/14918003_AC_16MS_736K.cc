#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const double eps=1e-8;

int cmp(double x)
{
    if(fabs(x)<eps)return 0;
    if(x>0)return 1;
    return -1;
}

struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool  operator <(const point &a)const
    {
        return x<a.x;
    }
    point operator -(const point &a)const
    {
        return point(x-a.x,y-a.y);
    }
    point operator +(const point &a)const
    {
        return point(x+a.x,y+a.y);
    }
    point operator /(const double &a)const
    {
        return point(x/a,y/a);
    }
    point operator *(const double &a)const
    {
        return point(x*a,y*a);
    }
};

double det(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}

struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
    bool operator <(const line &l)const
    {
        return a.x<l.a.x;
    }
};

bool parallel(line a,line b)
{
    return !cmp(det(a.a-a.b,b.a-b.b));
}

//bool line_make_point(line a,line b,point &res)
//{
//    point tmp1,tmp2,tmp3;
//    if(parallel(a,b))return false;
//    double s1=det(a.a-b.a,b.b-b.a);
//    double s2=det(a.b-b.a,b.b-b.a);
//    res=(a.b*s1-a.a*s2)/(s1-s2);
//    return true;
//}
void line_make_point(line a,line b,point &res)
{
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(a.b*s1-a.a*s2)/(s1-s2);
}

int main()
{
    line a,b;
    point res;
    int t;
    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(t--)
    {
        cin>>a.a.x>>a.a.y>>a.b.x>>a.b.y>>b.a.x>>b.a.y>>b.b.x>>b.b.y;
        if(parallel(a,b))
        {
            if(parallel(line(a.a,b.a),b))
                cout<<"LINE"<<endl;
            else cout<<"NONE"<<endl;
        }
        else
        {
            line_make_point(a,b,res);
            printf("POINT %.2f %.2f\n",res.x,res.y);
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}

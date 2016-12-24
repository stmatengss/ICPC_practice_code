#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

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

bool pending(const point &a,const line &b)
{
    return det(a-b.a,a-b.b)<0;
}

line l[5004];
//point p[1004];
int n,m;
int le,ri,mid;
int num[5004];
//int res[5004];
double x_1,y_1,x_2,y_2,x,y;

int main()
{
    int i,j,k;
    point tmp;
    while(cin>>n,n)
    {
        cin>>m>>x_1>>y_1>>x_2>>y_2;
        memset(num,0,sizeof(num));
//        memset(res,0,sizeof(res));
        for(i=0;i<n;i++)
        {
            cin>>l[i].a.x>>l[i].b.x;
            l[i].a.y=y_1, l[i].b.y=y_2;
        }
//        sort(l,l+n);
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            le=0,ri=n;
            tmp=point(x,y);
            if(pending(tmp,l[n-1])==false){num[n]++; continue;}
            if(pending(tmp,l[0])==true){num[0]++; continue;}
            while(ri-le>1)
            {
                mid=(le+ri)/2;
                if(pending(tmp,l[mid])==false)le=mid;
                else ri=mid;
            }
            if(pending(tmp,l[mid])==false)num[ri]++;
            else num[mid]++;
        }
        cout<<"Box"<<endl;
        for(i=0;i<=n;i++)
        {
            cout<<i<<": "<<num[i]<<endl;
//            cout<<i<<"| "<<num[i]<<endl;
        }

//        for(i=1;i<=m;i++)
//        {
//            if(res[i])
//            cout<<i<<": "<<res[i]<<endl;
//        }
    }

    return 0;
}

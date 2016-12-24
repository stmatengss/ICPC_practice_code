#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
     long long t;
     if(b==0) 
       return a;
     return gcd(b,a%b);
}
void exgcd(long long a,long long b,long long &m,long long  &n)
{
     if(b==0)
     {
          m=1;
          n=0;
          return ;   
     }
     exgcd(b,a%b,m,n);
     long long t=m;
     m=n;
     n=t-a/b*n; 
}
int main()
{
    long long x,y,m,n,l,a,b,k1,k2,t;
    while(cin>>x>>y>>m>>n>>l)
    {
        a=n-m;
        b=l;
        n=x-y;
        long long r=gcd(a,b);
        if(n%r)
        {
                  cout<<"Impossible"<<endl;
                  continue;
        }
        a=a/r;
        b=b/r;
        n=n/r;
        exgcd(a,b,k1,k2);
        t=n*k1/b;
        k1=n*k1-t*b;
        if(k1<0)
          k1+=b;
        cout<<k1<<endl;
    }
    return 0;
}
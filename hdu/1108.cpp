////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 23:25:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
          if(b==0)return a;
          return gcd(b,a%b);
}

int lcm(int a,int b)
{
          int max,min;
          max=a>=b?a:b;
          min=a<b?a:b;
          return a*b/gcd(max,min);
}
int main()
{
    int m,n;
    while(cin>>m>>n)cout<<lcm(m,n)<<endl;
    return 0;
}

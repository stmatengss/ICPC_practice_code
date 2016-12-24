////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 21:56:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#define ll long long 

using namespace std;

ll gcd(ll a,ll b)
{
          if(b==0)return a;
          return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
          ll max,min;
          max=a>=b?a:b;
          min=a<b?a:b;
          return a*b/gcd(max,min);
}

ll result,temp;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int num;
       cin>>num;
       result=1;
       while(num--)
       {
           cin>>temp;
           result=lcm(result,temp);        
       }
       cout<<result<<endl;
    }
    return 0;
}

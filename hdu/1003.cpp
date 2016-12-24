////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-17 21:01:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
using namespace std;

int dp[100005]={0};
int a[100005];
int i,j;
int le,ri;
int le_max,ri_max,_max;

int main()
{
    int t;
    int n;
    cin>>t;
    int counter=1;
    while(t--)
    {
              cout<<"Case "<<counter++<<":"<<endl;
              cin>>n;
              le=1,ri=1;
              le_max=1,ri_max=1;
              //_max=-1<<22;
              for(i=1;i<=n;i++)cin>>a[i];
              dp[1]=a[1];
              _max=dp[1];
              for(i=2;i<=n;i++)
              {
                 if(dp[i-1]+a[i]>=a[i])
                 {
                    dp[i]=dp[i-1]+a[i];
                     ri++ ;
                 }
                 else
                 {
                     dp[i]=a[i];
                     le=i;
                     ri=i;
                 }
                 if(dp[i]>_max)
                     {
                        _max=dp[i];
                        le_max=le;
                        ri_max=i;
                     }              
              }
              cout<<_max<<' '<<le_max<<' '<<ri_max<<endl;
              if(t)cout<<endl;
    }
    //while(1){}
    return 0;
}
/*
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
4 0 0 2 0
6 2 7 -9 5 4 3
4 0 0 -1 0
7 -1 -2 -3 -2 -5 -1 -2
6 -1 -2 -3 1 2 3
*/

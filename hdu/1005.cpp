////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-17 22:38:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
using namespace std;

int a,b,n;
int f[52];
int i,j;

void fun()
{
     for(i=3;i<=50;i++)f[i]=(a*f[i-1]+b*f[i-2])%7;
}

int main()
{
    f[1]=1;
    f[2]=1;
    while(1)
    {
            cin>>a>>b>>n;
            if(a==0)break;
            fun();
            cout<<f[n%49]<<endl;
    }
    return 0;
}

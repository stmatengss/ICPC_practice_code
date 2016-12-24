////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-13 00:21:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

char s[1010];
int mod;
int len;
int i;
int num;

int main()
{
    while(scanf("%s %d",s,&mod)!=EOF)
    {
       num=0;
       len=strlen(s);
       for(i=0;i<len;i++)
       {
          num=(num*10+(s[i]-'0'))%mod;
       }
       cout<<num<<endl;
    }
   return 0;
}

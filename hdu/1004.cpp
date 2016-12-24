////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-17 21:45:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:376KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>

using namespace std;

int num[1010];
string name[1010];
int _max,sum,state,n;
string temp;\
int i,j;

int main()
{
    while(1)
    {
       cin>>n;
       if(n==0)break;
       memset(num,0,sizeof(num));
       sum=0;
       for(i=1;i<=n;i++)
       {
          cin>>temp;
          state=0;
          for(j=1;j<sum;j++)
          {
             if(temp==name[j]){state=1; num[j]++;}
          }
          if(state==0)
          {  name[++sum]=temp;  
          num[sum]++;}
       }
       _max=1;
       for(i=1;i<=sum;i++)if(num[i]>num[_max])_max=i;
       cout<<name[_max]<<endl;             
    }
  return 0;   
}

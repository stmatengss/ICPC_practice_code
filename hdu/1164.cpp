////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-13 00:00:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:404KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#define N  65550
using namespace std;

bool pre[N];
int counter;
int primer[7000];
int i,j;

void tab()
{
     counter=0;
     memset(pre,true,sizeof(pre));
     pre[1]=false;
     //pre[2]=true;
     for(i=2;i<N;i++)
     {
        if(pre[i]==true)
        {
           primer[counter++]=i;
           for(j=2*i;j<N;j+=i)pre[j]=false;  
        }
     }
}

int main()
{
    tab();
    int num,st,st2=0;
    while(cin>>num)
    {
        st=0;
       // if(st2==0)st2=1;
       // else cout<<endl;
        //be=1;
        if(pre[num]==true)cout<<num;
        else
        {
           //while(num!=1)
           {
              for(i=0;i<=counter;i++)
              {
                 if(num==1)break;
                 if(num%primer[i]==0)
                 {
                    if(st)cout<<'*'<<primer[i];
                    else {cout<<primer[i]; st=1;}
                    num/=primer[i];
                    i--;
                 }
              }
           } 
        }
        cout<<endl;
                   
    }
    return 0;  
}

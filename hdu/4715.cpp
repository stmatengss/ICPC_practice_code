////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-05 13:13:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4715
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:1336KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include<cmath>
#define MAX 1000100
using namespace std;

bool prime[MAX];
int num[10000];
int size;

void Prime(){
    num[1]=2;
    size=1;   
    for(int i=2;2*i<MAX;++i)prime[2*i]=true;  
    for(int i=3;i*i<MAX;i+=2){  
        if(!prime[i]){  
            num[++size]=i;  
            for(int j=i*i;j<MAX;j+=i)prime[j]=true;  
        }  
    }  
}  

int n,m;
int flag;

int main()
{
    int t;
    int i;
    Prime();
    cin>>t;
    while(t--)
    {
         flag=0;
         cin>>n;
         m=n>0?n:-n;
         for(i=1;i<=size;i++)
         {
            if(prime[num[i]+m]==false){flag=1;break;}
         }
         if(flag==0)cout<<"FAIL"<<endl;
         else{
         if(n>0)cout<<(num[i]+m)<<' '<<(num[i])<<endl;
         else cout<<(num[i])<<' '<<(num[i]+m)<<endl;
         }     
    }
    
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-08-31 13:06:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4282
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
//#include<iostream>
#include<math.h>

//using namespace std;

long long mypower(long long m,long long n )
{
     long long temp=m;
     long long i;
     for(i=1;i<n;i++)
     temp*=m;
     return temp;
}

long long k;
long long x,y,z;
long long num;
long long sq;
long long k_temp;

int main()
{
    
    while(1)
    {
        scanf("%I64d",&k);
        if(k==0)break;
        //=sqrt(k)
        num=0;
        k_temp=sqrt((double)k);
        if(k_temp*k_temp==k)
        {
            num+=(k_temp-1)/2;
        }
        for(z=3;z<31;z++)
        {
            for(x=1;;x++)
            {
                   sq=mypower(x,z);
                   if(sq>=k>>1)break;
                   for(y=x+1;;y++)
                   {
                   if(mypower(y,z)+sq+x*y*z>k)break;
                   if(mypower(y,z)+sq+x*y*z==k)
                   {
                       num++;
                       break;
                   }
                   }      
            }
        }
        printf("%I64d\n",num);
    }
    return 0;
}

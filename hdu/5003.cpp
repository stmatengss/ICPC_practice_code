////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-13 21:29:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <set>  
#include <map>  
#include <algorithm>  
#include <cmath> 
using namespace std;

double a[60];
double b[60];
int i;
int t,n;
double sum,temp;
double m;

void tab()
{
     
     a[1]=1.00000000;    
     for(i=2;i<54;i++)
      a[i]=a[i-1]*95.0/100.0; 
}

int main()
{
    tab();
    cin>>t;
    while(t--)
    {
      sum=0;
      //m=1; 
      cin>>n;
      for(i=0;i<n;i++)
      {
         cin>>b[i];
      }
      sort(b,b+n);
      for(i=n-1;i>=0;i--)
         sum+=b[i]*a[n-i];
      printf("%.10lf\n",sum);        
    }
    return 0;
/*
4
2
530 478
*/
}

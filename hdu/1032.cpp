////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-18 18:39:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int fun(int n)
{
    int sum=1;
    while(1)
    {
       if(n==1)break;
       if(n%2==1)n=3*n+1;
       else n=n/2;
       sum++;
    }
    return sum;
} 

int n,m;
int _max,temp;
int i;

int main()
{
    while(cin>>n>>m)
    {
       _max=0;
       cout<<n<<' '<<m;
       if(n>m)
       {
          temp=n;
          n=m;
          m=temp;
       }
       for(i=n;i<=m;i++)
       {    
            temp=fun(i);
            if(temp>_max)_max=temp;
       }
       cout<<' '<<_max<<endl;
    }
    return 0;
}

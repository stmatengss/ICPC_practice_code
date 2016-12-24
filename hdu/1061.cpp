////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 22:50:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>

int a[21]={0,1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9,0};
int t,temp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&temp);
    printf("%d\n",a[temp%20]);
    }
    return 0;
}

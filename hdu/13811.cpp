////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-09-12 21:43:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1381
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:19960KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define N 20000010

char hash[N];
char s[1000000];
int ch[400];
int n,m,temp,i,j;
int len,sum,num;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    { 
       memset(hash,0,sizeof(hash));
       memset(ch,0,sizeof(ch));
       temp=1;  
       sum=0;     
       scanf("%d%d",&n,&m);
       scanf("%s",s);
       len=strlen(s);
       for(i=0;i<len;i++)
       {
            if(ch[s[i]]==0){ ch[s[i]]=temp++;}
            //if(temp==m)break;
       }
       for(i=0;i<len-n+1;i++)
       {
            num=0;
            for(j=i;j<i+n;j++)
            {
                num=ch[s[j]]+num*(m);

            }
            if(hash[num]==0)
            {
                sum++;
                     hash[num]=1;
            }
       }
       printf("%d\n",sum);
       //if(t)    printf("\n");
    }
  //while(1){}
    return 0;
}
/*
3 4
daababac
*/

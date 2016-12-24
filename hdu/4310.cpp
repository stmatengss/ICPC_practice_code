////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2014-04-20 19:40:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4310
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>

int main()
{
    int i,j,n;
    int hp[100],dp[100],temp,sum,ans;
    while(scanf("%d",&n)!=EOF)
    {
                ans=0;              sum=0;
           for(i=1;i<=n;i++)
           {
              scanf("%d %d",&hp[i],&dp[i]);
              sum+=dp[i];
              }
           for(i=1;i<=n;i++)
              for(j=i+1;j<=n;j++)
              if((double)hp[i]/dp[i]>(double)hp[j]/dp[j])
              {
              temp=hp[i];hp[i]=hp[j];hp[j]=temp;
              temp=dp[i];dp[i]=dp[j];dp[j]=temp;
              }   
      //     for(i=1;i<=n;i++)
        //      for(j=1;j<=n;j++)
          //    if(dp[i]>dp[j]){temp=dp[i];dp[i]=dp[[j];dp[j]=temp;}   
           for(i=1;i<=n;i++)
              {
                            ans+=sum*hp[i];
                            sum-=dp[i];
              }
              printf("%d\n",ans);
                      
    }
    return 0;
    
}

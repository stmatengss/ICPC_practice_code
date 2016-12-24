#include<stdio.h>
#include<string.h>
int dp[1005][10050];//dp[i][j]???i??????????j?????;
int num[10050];//???????????;
int main(){
    int n,m,a,b,x;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF){
        memset(num,0,sizeof(num));
        for(int i=0;i<m;i++){
            scanf("%d",&x);
            num[x]++;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=num[1];i++) dp[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=b;j++){//??????b;
                for(int k=0;k<=num[i];k++){
                    if(j>=k) {
                    dp[i][j]+=dp[i-1][j-k];//??????;
                    dp[i][j]%=1000000;
                    }
                }
            }
        }
        int ans=0;
        for(int i=a;i<=b;i++){
            ans+=dp[n][i];
            ans%=1000000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
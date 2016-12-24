////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-08 14:35:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4778
////Problem Title: 
////Run result: Accept
////Run time:3931MS
////Run memory:17996KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>

using namespace std;

const int maxn=22;

int dp[1<<maxn],num[maxn][10],a[10],b[10];
int G,B,S,n;

int main()
{
    int t;
    int i,j,k,tmp;
    while(cin>>G>>B>>S)
    {
        if(G==0&&B==0&&S==0)break;
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        for(i=0;i<B;i++)
        {
            cin>>n;
            for(j=0;j<n;j++)
            {
                cin>>tmp;
                num[i][tmp]++;
            }
        }
        dp[0]=0;
        for(i=1;i<=(1<<B);i++)
        {
            dp[i]=-100000;
            memset(a,0,sizeof(a));
            for(j=0;j<B;j++)
            {
                if((i&(1<<j))==0)
                {
                    for(k=1;k<=G;k++)
                    {
                        a[k]+=num[j][k];
                    }
                }
            }
            for(k=1;k<=G;k++)
                a[k]%=S;
            for(j=0;j<B;j++)
            {
                if((i&(1<<j)))
                {
                    int ans=0;
                    for(k=1;k<=G;k++)b[k]=a[k];
                    for(k=1;k<=G;k++)
                    {
                        b[k]+=num[j][k];
                        ans+=b[k]/S;
                    }
//                    cout<<ans<<endl;
                    if(ans)dp[i]=max(dp[i],ans+dp[i^(1<<j)]);
                    else dp[i]=max(dp[i],-dp[i^(1<<j)]);
//                    cout<<"dp:"<<i<<":"<<dp[i]<<endl;
                }
            }
        }
        cout<<dp[(1<<B)-1]<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
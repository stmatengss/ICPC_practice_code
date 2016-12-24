////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-29 15:25:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1423
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:5520KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int f[1005][1005],a[1005],b[1005],i,j,t,n1,n2,maxn;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        for(i=1;i<=n1;i++) scanf("%d",&a[i]);
        scanf("%d",&n2);
        for(i=1;i<=n2;i++) scanf("%d",&b[i]);
        memset(f,0,sizeof(f));
        for(i=1;i<=n1;i++)
        {
            maxn=0;
            for(j=1;j<=n2;j++)
            {
                f[i][j]=f[i-1][j];
                if (a[i]>b[j]&&maxn<f[i-1][j]) maxn=f[i-1][j];
                if (a[i]==b[j]) f[i][j]=maxn+1;
            }
        }
        maxn=0;
        for(i=1;i<=n2;i++) if (maxn<f[n1][i]) maxn=f[n1][i];
        printf("%d\n",maxn);
        if(t!=0)
        {
            cout<<endl;
        }
    }
    return 0;
}

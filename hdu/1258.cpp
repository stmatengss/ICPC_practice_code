////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-23 10:48:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1258
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct po{
    int s[14];
    int len;
    int operator< (const po& a)const{
        return len<a.len;
    }
};
int sum,n,counter;
int num[14];
int amount[14];
int used[104];
int res[14];
int resnum[14];
po out[10000];

void dfs(int now,int x,int p)
{
    int i,j;
    if(now==sum)
    {
        counter++;
//        int len=0;
        for(i=1;i<=x;i++)
            for(j=1;j<=resnum[i];j++)
                printf((i==x&&j==resnum[i])?"%d\n":"%d+",res[i]);
//               len++,out[counter].s[len]=res[i];
//        out[counter].len=len;
        return;
    }
    if(x==n||now>sum)return;
    for(i=p+1;i<=n;i++)
    {
        for(j=amount[i];j>=1;j--)
        {
            res[x+1]=num[i];
            resnum[x+1]=j;
            dfs(now+num[i]*j,x+1,i);
        }
    }
}

int main()
{
    int i,j,tmp;
    while(cin>>sum>>n&&sum!=0&&n!=0)
    {
        counter=0;
        memset(used,0,sizeof(used));
        for(i=1;i<=n;i++)
            scanf("%d",&tmp),used[tmp]++;
        printf("Sums of %d:\n",sum);
        n=0;
        for(i=100;i>=1;i--)
        {
            if(used[i])n++,num[n]=i,amount[n]=used[i];
        }
        dfs(0,0,0);
        if(counter==0)
            printf("NONE\n");
//        else
//        {
//            sort(out+1,out+counter+1);
//            for(i=1;i<=counter;i++)
//            {
//                for(j=1;j<=out[i].len;j++)
//                {
//                    printf(j!=out[i].len?"%d+":"%d\n",out[i].s[j]);
//                }
//            }
//        }
    }
//    cout << "Hello world!" << endl;
    return 0;
}

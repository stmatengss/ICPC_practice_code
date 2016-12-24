////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-21 14:38:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1572KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int isprime[244];
int num[24];
int used[24];
int n;

void table()
{
    int i,j;
    isprime[1]=1;
    for(i=2;i<=240;i++)
    {
        if(isprime[0]==0)
        {
            for(j=2*i;j<=240;j+=i)
                isprime[j]=1;
        }
    }
}

void dfs(int len)
{
    if(len==n&&isprime[(num[n]+num[1])]==0)
    {
        for(int i=1;i<n;i++)printf("%d ",num[i]);
        printf("%d\n",num[n]);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&isprime[(i+num[len])]==0)
        {
            used[i]=1;
            num[len+1]=i;
            dfs(len+1);
            used[i]=0;
        }
    }
}

int main()
{
    table();
    int tcase=1;
    while(cin>>n)
    {

        printf("Case %d:\n",tcase++);
        if(n&1){cout<<endl;continue;}
        memset(used,0,sizeof(used));
        num[1]=1;
        used[1]=1;
        dfs(1);
        cout<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

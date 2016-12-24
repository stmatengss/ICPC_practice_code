////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-01 15:09:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:9412KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>

using namespace std;

int sum[1000004];
int num[1000004];

int main()
{
    int i,j;
    int n,m;
    for(i=1;i<=9;i++)
    {
        if(i>=4)sum[i]=1;
        if(i==4)num[i]=1;
    }
    for(i=10;i<=1000000;i++)
    {
        if(num[i/10]||i%100==62||i%10==4)
        {
            sum[i]=sum[i-1]+1;
            num[i]=1;
        }
        else
        {
            sum[i]=sum[i-1];
        }
    }
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        cout<<(m-n+1-(sum[m]-sum[n-1]))<<endl;
//        printf("%d\n",m-n+1-(sum[m]-sum[n-1]));
    }
//    cout << "Hello world!" << endl;
    return 0;
}

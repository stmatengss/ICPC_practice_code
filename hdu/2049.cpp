////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-27 16:00:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

//D(n) = n! [(-1)^2/2! + бн + (-1)^(n-1)/(n-1)! + (-1)^n/n!].

long long d[24];
long long c[24][24];
long long a[24];

int table()
{
    int i,j;
    a[0]=1;
    for(i=1;i<=21;i++)
        a[i]=a[i-1]*i;
    d[1]=0,d[2]=1;
    for(i=3;i<=21;i++)
    {
        d[i]=(i-1)*(d[i-1]+d[i-2]);
    }
    c[0][0]=1;
    for(i=1;i<=21;i++)
    {
        c[i][0]=1;
        for(j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}

int main()
{
    table();
    int n,m;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<c[n][m]*d[m]<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

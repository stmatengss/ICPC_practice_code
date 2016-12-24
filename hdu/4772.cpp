////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-08 20:33:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4772
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#define FOR(i) for(i=0;i<n;i++)
#define FORN(i,n) for(i=0;i<n;i++)
#define IN(i) cin>>(i);
#define OUT(i) cout<<(i)<<endl;
#define OUTMAT(a,i,n) cout<<(a)<<(i==n-1?"\n":" ");
#define INB(i) cin>>(i);if(i==0)break;
#define IFEQ(a,b,c) if(a==b)c++;
#define ZERO(a) a=0;
#define MAX(a,b,c) a=max(b,c);
#define CLR(a) memset(a,0,sizeof(a));
using namespace std;

int n;
int a[34][34];
int b[34][34];
int c[4];

int main()
{
    int i,j,k;
    while(1)
    {
        INB(n)
        CLR(c)
        FOR(i)FOR(j)IN(a[i][j])
        FOR(i)FOR(j)IN(b[i][j])
        FOR(i)FOR(j)IFEQ(a[i][j],b[i][j],c[0])
        FOR(i)FOR(j)IFEQ(a[j][n-i-1],b[i][j],c[1])
        FOR(i)FOR(j)IFEQ(a[n-i-1][n-j-1],b[i][j],c[2])
        FOR(i)FOR(j)IFEQ(a[n-j-1][i],b[i][j],c[3])
        sort(c,c+4);
        OUT(c[3]);
//        FOR(i)FOR(j)OUTMAT(a[i][j],j,n)
    }

    return 0;
}

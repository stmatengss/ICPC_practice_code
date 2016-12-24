////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-09 18:27:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define FOR(i) for(i=0;i<n;i++)
#define FORN(i,n) for(i=0;i<n;i++)
#define FORBN(i,b,n) for(i=b;i<n;i++)
#define FORM(i,m) for(i=1;i<=m;i++)
#define FORBM(i,b,m) for(i=b;i<=m;i++)
#define IN(i) cin>>(i);
#define OUTS(i) cout<<(i);
#define OUT(i) cout<<(i)<<endl;
#define OUTMAT(a,i,n) cout<<(a)<<(i==n-1?"\n":" ");
#define INB(i) cin>>(i);if(i==0)break;
#define IFEQ(a,b,c) if(a==b)c++;
#define ZERO(a) a=0;
#define MAX(a,b,c) a=max(b,c);
#define CLR(a) memset(a,0,sizeof(a));
#define BFSQUE(a,b) a=b.front(); b.pop();

using namespace std;

int main()
{
    int i;
    int n;
    double res;
    double tmp;
    while(cin>>n)
    {
//        cin>>tmp;
        scanf("%lf",&tmp);
        res=1.0*n*tmp;
//        cin>>tmp;
        scanf("%lf",&tmp);
        res+=tmp;
        FORM(i,n)scanf("%lf",&tmp),res-=2.0*(n+1-i)*tmp;
        printf("%.2lf\n",res/(n+1));
    }
//    cout << "Hello world!" << endl;
    return 0;
}

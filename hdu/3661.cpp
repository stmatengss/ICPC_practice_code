////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:13:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3661
////Problem Title: 
////Run result: Accept
////Run time:1263MS
////Run memory:1840KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN=2007;

long long i,j,k,n,m,t,x,y,ans;
long long a[MAXN],b[MAXN];

int main()
{
    while (cin>>n>>t)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=0;
        for (i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for (i=0;i<n;i++)
        {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        for (i=0;i<n;i++)
        {
            x=a[i]+b[i];
            if (x>t)
            {
                ans+=x-t;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-29 20:55:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5265
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:2592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll num[100004];
ll* pos;
ll res;
int n,p;

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    ll tmp;
    int t;
    int i,j;
    num[0]=1;
    while(cin>>n>>p)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&tmp),num[i]=tmp%p;
        sort(num,num+n);
        res=-1;
        res=(num[n-1]+num[n-2])%p;
//        for(i=1;i<n;i++)
        for(i=0;i<=n-1;i++)
        {
            pos=upper_bound(num,num+i,p-num[i]-1);
            if(pos!=num&&pos!=num+i)
                res=max(res,num[i]+*(pos-1));
            if(res==p-1)break;

        }
//        if(n==2)res=(num[0]+num[1])%p;
        cout<<res<<endl;
    }

//    cout << "Hello world!" << endl;
    return 0;
}

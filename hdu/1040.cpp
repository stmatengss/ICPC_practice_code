////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 18:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int num[1004];

int main()
{
    int t;
    int n;
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        for(i=0;i<n;i++)
            cout<<num[i]<<(i==n-1?"\n":" ");
    }
    return 0;
}

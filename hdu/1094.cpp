////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-23 11:24:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a,b,n;
    int t;
    while(cin>>n)
    {
        b=0;
        for(int i=0;i<n;i++)
            cin>>a,b+=a;
            cout<<b<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

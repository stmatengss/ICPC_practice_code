////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-23 11:23:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a,b,n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        b=0;
        for(int i=0;i<n;i++)
            cin>>a,b+=a;
            cout<<b<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

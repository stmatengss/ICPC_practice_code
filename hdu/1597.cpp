////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-10 13:05:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll k,n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>k;
        n=(sqrt(8.0*(k-1)+1.0)-1)/2;
        n=(k-(n+1)*n/2)%9;
//        cout<<n<<":";

        cout<<(n==0?9:n)<<endl;
    }
    return 0;
}

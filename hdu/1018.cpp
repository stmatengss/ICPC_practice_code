////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 17:54:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
const double pi=acos(-1.0);
double res;

int main()
{
    int t;
    double n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res=(log(sqrt(2.0*pi*n))+n*(log(n)-1.0))/(log(10.0));
        cout<<(ll(res)+1)<<endl;
    }
    return 0;
}

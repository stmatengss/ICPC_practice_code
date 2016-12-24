////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 15:25:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1748KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>

using namespace std;

//int dp[104][104];
//int num[104][104];
int n,m;



int main()
{
    int i,j;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<((n%m==0)?"YES":"NO")<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}


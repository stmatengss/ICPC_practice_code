////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-09 16:34:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1795
////Problem Title: 
////Run result: Accept
////Run time:2854MS
////Run memory:1652KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isprime[10074];
vector<int> prime;

void tab()
{
    for(int i=2;i<=10024;i++)
    {
        if(isprime[i]==0)
        {
            prime.push_back(i);
            for(int j=2*i;j<=10024;j+=i)
                isprime[j]=1;
        }
    }
}

int main()
{
    int t;
    int num;
    tab();
    cin>>t;
    while(t--)
    {
        cin>>num;
        cout<<*upper_bound(prime.begin(),prime.end(),num)<<endl;
    }
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-06 16:24:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2578
////Problem Title: 
////Run result: Accept
////Run time:1450MS
////Run memory:3732KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
//int dp[104][104];
//int num[104][104];
ll n,k;

vector<int>num;
map<int,int>mp;
int tmp;
//cin.sync_with_stdio(false);
int main()
{
    int i,j;
    int t;
    int res=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        res=0;
        num.clear();
        mp.clear();
        for(i=1;i<=n;i++)
        {
             scanf("%d",&tmp);
             if(mp[tmp]==0)
             {
                mp[tmp]=1;
                num.push_back(tmp);
             }
        }
        for(i=0;i<num.size();i++)
        {
            if(mp[k-num[i]])
                res++;
        }
        cout<<res<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

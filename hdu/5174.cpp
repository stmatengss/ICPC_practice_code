////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-10-19 11:01:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5174
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;
int n;
ll tmp;
const ll intmax=2147483647;
vector<ll>num;
map<ll,int>mp;
int res;

int main()
{
    int i,j,k;
    j=1;//const ll INT_MAX=2147483647;
    while(cin>>n)
    {
        res=0;
        num.clear();
        mp.clear();
        for(i=1;i<=n;i++)
        {
            cin>>tmp;
            if(mp[tmp]==0)
                num.push_back(tmp);
            mp[tmp]++;
        }
        sort(num.begin(),num.end());
        if(num.size()==1)
        {
            cout<<"Case #"<<j++<<": -1"<<endl;
            continue;
        }
        for(i=0;i<num.size();i++)
        {
            tmp=(num[(num.size()+i-1)%num.size()]+num[(num.size()+i)%num.size()])%intmax;
            //tmp=tmp>intmax?tmp%intmax:intmax;
            if(tmp==num[(num.size()+i+1)%num.size()])
            {
               res+=mp[num[i]];
            }
        }
        cout<<"Case #"<<j++<<": "<<res<<endl;

    }
//    cout << "Hello world!" << endl;
    return 0;
}

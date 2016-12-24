////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-01 16:17:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4135
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll>factor;

void findfactor(ll num)
{
    factor.clear();
    for(ll i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            factor.push_back(i);
            while(num%i==0)num/=i;
        }
    }
    if(num>1)factor.push_back(num);
}

ll fun(ll num)
{
    ll res=0;
    ll ans,counter;
    ll i,j;
    for(i=1;i<(1<<factor.size());i++)
    {
        ans=1;
        counter=0;
        for(j=0;j<factor.size();j++)
        {
            if(i&(1<<(j)))
            {
                ans*=factor[j];
                counter++;
            }
        }
        if(counter&1)
            res+=num/ans;
        else
            res-=num/ans;
    }
//    cout<<res<<endl;
    return num-res;
}

int main()
{
    ll x,y,n;
    int t;
    cin>>t;
    int tcase=1;
    while(t--)
    {
        cin>>x>>y>>n;
        findfactor(n);
        cout<<"Case #"<<(tcase)<<": "<<(fun(y)-fun(x-1))<<endl;
        tcase++;
    }
//    cout << "Hello world!" << endl;
    return 0;
}

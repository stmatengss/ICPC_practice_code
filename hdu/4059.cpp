////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-11-04 16:12:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4059
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
ll mm;

vector<ll>factor;

ll quick_mod(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=(res*a)%mod;
        a=(a*a)%mod;
        n=n>>1;
    }
    return res;
}

void find_factor(ll num)
{
    factor.clear();
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            factor.push_back(i);
            while(num%i==0)
                num/=i;
        }
    }
    if(num>1)factor.push_back(num);
}

ll cal(ll num)
{
    return (((num*(num+1)%mod)*(2*num+1)%mod)*(((3*num*num%mod)+3*num-1)%mod)%mod*mm%mod);
}

ll pow(ll num)
{
    return (((num*num%mod)*num%mod)*num%mod);
}

ll fun(ll num)
{
    ll res=cal(num);
    ll ans,counter;
    ll i,j;
    ll rest,sum;
    for(i=1;i<(1<<factor.size());i++)
    {
        ans=1;
        counter=0;
        for(j=0;j<factor.size();j++)
        {
            if(i&(1<<j))
            {
                ans*=factor[j];
                counter++;
            }
        }
        rest=num/ans;
        sum=pow(ans)*(cal(rest))%mod;
        if(counter&1)
            res=((res-sum)%mod+mod)%mod;
        else
            res=(sum+res)%mod;
    }
    cout<<res<<endl;
}

int main()
{
    int t;
    ll num;
    mm=quick_mod(30,mod-2);
//    cout<<mm<<endl;
//cout<<cal(4)<<endl;
    cin>>t;
    while(t--)
    {
        cin>>num;
        find_factor(num);
//        cout<<cal(num-1)<<endl;
        fun(num);
    }
    return 0;
}
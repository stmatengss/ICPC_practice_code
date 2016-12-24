#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
int t;
int n;
ll a,b,mod;
int i,j;
ll sum;

ll quick_pow(ll a,ll b,ll mod)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return res;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>mod;
		cin>>n;
	
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>a>>b;
			sum=(sum+quick_pow(a,b,mod))%mod;
		}
		cout<<sum<<endl;
	}
	return 0;
}
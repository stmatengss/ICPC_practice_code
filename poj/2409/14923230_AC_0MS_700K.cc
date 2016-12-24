#include<iostream>
#include<cstdio>

typedef long long ll;
using namespace std;

const int mod=1000000007;

int n,m;

ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

ll quick_mod(ll a,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1)res*=a;
		a*=a;
		n=n>>1;
	}
	return res;
}

int main()
{
	int i,j;
	ll res;
	int n,m;	
	while(cin>>m>>n,n,m)
	{
		res=0;
		for(i=1;i<=n;i++)
		{
			res+=quick_mod(m,gcd(n,i));
		}
		if(n&1)res+=quick_mod(m,(n/2+1))*n;
		else res+=quick_mod(m,n/2+1)*(n/2)+quick_mod(m,n/2)*(n/2);
		cout<<res/(2*n)<<endl;
	}
	return 0;
}

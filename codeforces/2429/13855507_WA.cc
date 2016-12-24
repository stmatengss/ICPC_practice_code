#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;

int prime[10000];

void find_prim(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(prime[i]==0)
		for(j=2*i;j<=n;j+=i)
			prime[j]=1;
	}
}

int Gcd(int x,int y)
{
	if(y==0)return x;
	return Gcd(y,x%y);
}

int main()
{
	ll lcm,gcd;
	ll temp;
	cin>>gcd>>lcm;
	ll ub=lcm/gcd;
	temp=ub-1;
	int ST=1;
	ll n=sqrt(ub);
	//find_prim(ub-1);
	while(n)
	{
		if(ub%n==0&&Gcd(ub/n,n)==1&&ub/n!=n)//prime[ub/n]==0&&prime[n]==0
		{
			cout<<gcd*n<<" "<<gcd*(ub/n)<<endl;
			ST=0;
			break;
		}
		n--;
	} 
	if(ST)cout<<"No"<<endl;
	return 0;
}
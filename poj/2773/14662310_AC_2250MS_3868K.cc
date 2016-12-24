#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int prime[1000004];

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}

int n,k;

int main()
{
	int i,j;
	while(cin>>n>>k)
	{
		
		int counter=0;
		if(n==1)
		{
			cout<<k<<endl;
		}
		else if(n==2)
		{
			cout<<((k-1)*2+1)<<endl;
		}
		else
		{
			k--;
			for(i=1;i<=n;i++)
			{
				if(gcd(n,i)==1)
				{
					prime[counter]=i;
					counter++;
				}

			}
			cout<<(prime[k%(counter)]+k/(counter)*n)<<endl;
		}
		
	}
	return 0;
}
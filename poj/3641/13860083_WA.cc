#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll; 
ll p,a;
int ST=1;

int main()
{
	int i,j;
	int n,temp,m;
	while(cin>>p>>a)
	{
		ST=0;
		if(p==0&&a==0)break;
		for(i=2;i<=sqrt(p)+1;i++)
			if(p%i==0)ST=1;
		if(ST)
		{
			n=p;
			m=a;
			temp=1;
			while(n)
			{
				if(n&1)temp=temp*m%p;
				m=m*m%p;
				n=n>>1;
			}
			if(temp%p==a)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}	
	}
}
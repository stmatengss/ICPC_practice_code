#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=1004;
char num[N];
int len;
ll power[50];
ll A,B,GCD;
ll front,back,num_len;

ll quick_pow(ll a,int n)
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

ll gcd(ll x,ll y)
{
	if(y==0)return x;
	return gcd(y,x%y); 
}

void init()
{
	int i;
	//ll temp=1;
	power[0]=1;
	for(i=1;i<=50;i++)
	power[i]=power[i-1]*10;
}

int main()
{
	init();
	int i,j;
	while(cin>>num)
	{
		front=0;
		len=strlen(num);
		back=num[len-4]-'0';
		num_len=len-6;
		for(i=2,j=num_len-1;i<=len-5;i++,j--)
		{
			front+=(num[i]-'0')*power[j];
		}
		A=front*9+back;//*power[num_len];
		B=9*power[num_len];
		GCD=gcd(A,B);
		cout<<(A/GCD)<<"/"<<(B/GCD)<<endl;
		memset(num,'\0',sizeof(num));			
	}
	return 0;
}
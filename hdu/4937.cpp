////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-09-01 12:58:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4937
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;
const double EPS=1e-6;
ll num;
ll ans;
ll tmp;
int lucky[6]={3,4,5,6};

bool zero(double n){
    return n < EPS && n > -EPS;
}

bool cmp(double a)
{
	return zero(a - (int) (a + 0.5));
}

int main()
{
	int t;
	ll i,j,k;
	int counter=1;
	ll a,b,c;
	ll delta;
	cin>>t;
	while(t--)
	{
		cin>>num;
		ans=0;
		cout<<"Case #"<<counter++<<": ";

		if(num>=3&&num<=6)
		{
			ans=-1;
//				cout<<"-1"<<endl;
		}
		else
		{
			for(i=2;i*i*i<=num;i++)
			{
				tmp=num;
				while(tmp)
				{
					if(!(tmp%i<=6&&tmp%i>=3))
						break;
					tmp/=i;
				}
				if(tmp==0)ans++;
			}
//			cout<<ans<<endl;
			for(i=3;i<=6;i++)
				for(j=3;j<=6;j++)
					for(k=3;k<=6;k++)
					{
						a=i,b=j,c=k-num;
						delta=b*b-4*a*c;
						if(delta>=0)
						{
							tmp=(ll)(sqrt(delta)+0.1);
							if(tmp*tmp==delta)
//							
							if((-b+tmp)%(2*a)==0)
							{
								tmp=(-b+tmp)/2/a;
								if(tmp>max(i,max(j,k)))
								{
									ans++;
								}
							}
							
						}
//						else if(delta==0)
//						{
//								if((-b+delta)/2/a>max(i,max(j,k))&&cmp((-b+delta)/2/a))
//									ans++;
//						}
					}
//			cout<<ans<<endl;
			for(i=3;i<=6;i++)
				for(j=3;j<=6;j++)
				{
//					delta=1.0*(num-j)/i;
					if((num-j)%i==0&&(num-j)/i>max(i,j))
						ans++;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

ll c(int m,int n)
{
	ll ans=1;
	int i,j=1;
	for(i=n;i>=n-m+1;i--)
	{
		ans*=i;
		while(ans%j==0&&j<=m)
		{
			ans/=j;
			j++;
		}
	}
	return ans;
}

int main()
{
		int a,b;
		while(cin>>a>>b&&!(a==0&&b==0))
		{
			swap(a,b);
			if(a==0||a==b)cout<<"1"<<endl;
			else if(a<b/2)cout<<c(a,b)<<endl;
			else cout<<c(b-a,b)<<endl;
		}
		return 0;
}
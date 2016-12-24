#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

ll c(int m,int n)
{
	if(m==0||m==n)return 1;
	//if(m==n)return 1;
	else return c(m-1,n-1)+c(m,n-1);
}

int main()
{
		int a,b;
		while(cin>>a>>b&&a!=0&&b!=0)
		{
			swap(a,b);
			if(a==0||a==b)cout<<"1"<<endl;
			else if(a<b/2)cout<<c(a,b)<<endl;
			else cout<<c(b-a,b)<<endl;
		}
}
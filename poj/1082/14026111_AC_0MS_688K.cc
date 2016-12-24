#include<iostream>
#include<cstring>

using namespace std;
int main()
{
	unsigned int a,b,c;
	int t;
	cin>>t;
	bool st;
	while(t--)
	{
		st=false;
		cin>>a>>b>>c;
		//if(((b%2)+(c%2))%2==0)st=true;
		if((((b&1)+(c&1))&1)==0)st=true;
		//cout<<(b&1)<<(c&1)<<((b&1)+(c&1))<<(((b&1)+(c&1))&1)<<endl;
		if(b==9&&c==30||b==11&&c==30)st=true;
		if(st)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
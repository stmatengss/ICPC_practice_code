#include<iostream>
#include<stack>

using namespace std;

stack<int>s;
int temp;

int main()
{
	int i;
	int n;
	long long res=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>temp;
		while(!s.empty()&&s.top()<=temp)
			s.pop();
		
		res+=s.size();
		s.push(temp);
	}
	cout<<res<<endl;
}
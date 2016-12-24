#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

const int D='A'-'a';
string s;
map<char,int>mp;
//bool operator < (const char a,const char b)
//{
//	if(a>='A'&&a<='Z')a-=D;
//	if(b>='A'&&b<='Z')b-=D;
//	return a<b;
//}

int cmp(const char &a,const char &b)
{
	return mp[a]<mp[b];
}

int main()
{
	int i;
	for(i=0;i<26;i++)
	{
		mp['A'+i]=2*i+1;
		mp['a'+i]=2*i+2;
	}
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		sort(s.begin(),s.end(),cmp);
		do{
			cout<<s<<endl;
		}while(next_permutation(s.begin(),s.end(),cmp));
	}
	
}
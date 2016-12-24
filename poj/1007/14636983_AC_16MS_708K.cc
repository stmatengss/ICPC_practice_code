#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct st{
	string s;
	int num;
	st(string s,int num):s(s),num(num){
	}
};

vector<st>a;
int n,len;
string in;
//vector<int>num;
int sum;

bool operator<(const st &a,const st &b)
{
	return a.num<b.num;
}

int main()
{
	int i,j,k;
//	s=vector<string>();
	cin>>len>>n;
	for(i=0;i<n;i++)
	{
		cin>>in;
		a.push_back(st(in,0));
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<len;j++)
			for(k=j+1;k<len;k++)
			{
				if(a[i].s[j]>a[i].s[k])
					sum++;
			}
		a[i].num=sum;
	}
	sort(a.begin(),a.end());
	for(i=0;i<n;i++)
	{
		cout<<a[i].s<<endl;
	}
	cout<<endl;
	return 0;
}
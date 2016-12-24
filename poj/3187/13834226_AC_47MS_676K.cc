#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int sum;
int num[10];
int c[10]; 

int cal()
{
	int i;
	int res=0;
	for(i=0;i<=n-1;i++)res+=num[i]*c[i];
	return res;
}

int main()
{
	int i,j;
	c[0]=1;
	cin>>n>>sum;
	for(i=1,j=n-1;i<=n-1;i++,j--)
	{
		c[i]=c[i-1]*j/i;
	}
	for(i=0;i<n;i++)num[i]=i+1;
	while(!(sum==cal()))
	{
		next_permutation(num,num+n);
	}
	for(i=0;i<n-1;i++)cout<<num[i]<<' ';
	cout<<num[n-1]<<endl;
	return 0;
}
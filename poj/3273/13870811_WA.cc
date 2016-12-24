#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int exp[100004];
int MAX;
int ub,lb,mid;

bool pending(int d)
{
	int counter=0;
	int sum=0,i;
	for(i=1;i<=n;i++)
	{
		sum+=exp[i];
		if(sum>d)
		{
			sum=0;
			counter++;
		}
	}
	if(counter>=m)return true;
	return false;
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>exp[i];
	MAX=*max_element(exp+1,exp+n+1);
	//cout<<MAX<<endl;
	lb=MAX,ub=10001;
	while(ub-lb>1)
	{
		mid=(lb+ub)/2;
		if(pending(mid))lb=mid;
		else ub=mid;
	}
	cout<<lb<<endl;
	return 0;
}
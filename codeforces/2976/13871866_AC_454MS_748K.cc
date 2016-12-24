#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[1004],b[1004];
double c[1004];
int n,k;
double lb,ub,mid;

bool pending(double d)
{
	double sum=0;
	int i;
	for(i=1;i<=n;i++)
		c[i]=-1.0*d*b[i]/100+1.0*a[i];
	sort(c+1,c+n+1);
	for(i=0;i<n-k;i++)
		sum+=c[n-i];
	if(sum>=0)return true;
	return false;		
}

int main()
{
	int i,j;
	while(cin>>n>>k&&n!=0)
	{
		for(i=1;i<=n;i++)
			cin>>a[i];	
		for(i=1;i<=n;i++)
			cin>>b[i];
		lb=0,ub=100;
		for(i=1;i<=50;i++)
		{
			mid=(lb+ub)/2;
			if(pending(mid))lb=mid;
			else ub=mid;
		}
		if((lb-(int)lb)<0.4999)cout<<(int(lb))<<endl;
		else cout<<(int(lb)+1)<<endl;
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
struct jewels{
	int no;
	int w;
	int v;
	double p;
};
jewels a[100004];
double v[100004];
int num[100004];

int cmp(jewels x,jewels y)
{
	return x.p>y.p;
}

bool pending(int d)
{
	int i;
	double sumv=0,sumw=0;
	for(i=0;i<n;i++)
		a[i].p=1.0*a[i].v-d*a[i].w;
	sort(a,a+n,cmp);
	for(i=1;i<=k;i++)
	{
		sumv+=a[i].v;
		sumw+=a[i].w;
	}	
	if(sumv/sumw>d)return true;
	return false;
}

int main()
{
	int i,j;
	cin>>n>>k;
	double mid,ub=0,lb=100000000;
	for(i=0;i<n;i++)
	{
		cin>>a[i].v>>a[i].w;
		a[i].no=i+1;
		a[i].p=1.0*a[i].v/a[i].w;
		if(a[i].p>ub)ub=a[i].p;
		if(a[i].p<lb)lb=a[i].p;
	}
	for(i=0;i<50;i++)
	{
		mid=(ub+lb)/2;
		if(pending(mid))lb=mid;
		else ub=mid;
	}
	for(i=0;i<n;i++)
		a[i].p=1.0*a[i].v-lb*a[i].w;
	sort(a,a+n,cmp);
	for(i=0;i<k;i++)
		num[i]=a[i].no;
	sort(num,num+k);
	for(i=0;i<k-1;i++)
		cout<<num[i]<<' ';
	cout<<num[k-1]<<endl;
	//double 
	return 0;
}
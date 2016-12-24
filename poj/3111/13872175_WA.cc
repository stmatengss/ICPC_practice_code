#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double esp=1e-8; 
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
int i;
double sumv=0,sumw=0;
int cmp(jewels x,jewels y)
{
	return x.p>y.p;
}


int main()
{
	int i,j;
	cin>>n>>k;
	double mid,pre=0,now=1;
	for(i=0;i<n;i++)
	{
		cin>>a[i].v>>a[i].w;
		a[i].no=i+1;
	}
	while(fabs(pre-now)<esp)
	{
		for(i=0;i<n;i++)
			a[i].p=1.0*a[i].v-now*a[i].w;
		sort(a,a+n,cmp);
		sumv=0;
		sumw=0;
		for(i=0;i<k;i++)
		{
			sumv+=a[i].v;
			sumw+=a[i].w;
		}	
		pre=now;
		now=sumv/sumw;
	}
	for(i=0;i<k-1;i++)
		cout<<a[i].no<<' ';
	cout<<a[k].no<<endl;
//		num[i]=a[i].no;
//	sort(num,num+k);
//	for(i=0;i<k-1;i++)
//		cout<<num[i]<<' ';
//	cout<<num[k-1]<<endl;
	//double 
	return 0;
}
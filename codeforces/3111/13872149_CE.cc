#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
const double esp=1e-8;
int N,K;
struct Je
{
    int v,w,id;
    double y;
}je[100005];
int cmp(Je je1,Je je2)
{
    return je1.y>je2.y;
}
int main()
{
//    freopen("test.txt","r",stdin);
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&je[i].v,&je[i].w);
        je[i].y=0;je[i].id=i+1;
    }
    double ps=1,s=0;
    while(fabs(s-ps)>esp)
    {
        for(int i=0;i<N;i++)
            je[i].y=je[i].v-s*je[i].w;
        sort(je,je+N,cmp);
        double sv=0,sw=0;
        for(int i=0;i<K;i++)
        {
            sv+=je[i].v;sw+=je[i].w;
        }
        ps=s;s=sv/sw;
    }
    for(int i=0;i<K;i++)
        printf("%d ",je[i].id);
    printf("\n");
    return 0;
}









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
	for(i=0;i<k;i++)
		num[i]=a[i].no;
	sort(num,num+k);
	for(i=0;i<k-1;i++)
		cout<<num[i]<<' ';
	cout<<num[k-1]<<endl;
	//double 
	return 0;
}
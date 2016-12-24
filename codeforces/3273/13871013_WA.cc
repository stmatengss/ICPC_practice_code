#include<iostream>
#include<cstdio>
#include<algorithm>
#include <numeric>
using namespace std;

int n,m;
int exp[100004];
int MAX;
int ub,lb,mid;

bool pending(int d)
{
	int counter=1;
	int sum=0,i;
	for(i=1;i<=n;i++)
	{
		sum+=exp[i];
		if(sum>d)
		{
			sum=exp[i];
			counter++;
		}
	}
	if(counter>m)return true;
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
	lb=MAX,ub=accumulate(exp+1,exp+n+1,0);
	while(ub-lb>1)
	{
		mid=(lb+ub)/2;
		if(pending(mid))lb=mid;
		else ub=mid;
	}
	cout<<ub<<endl;
	return 0;
}

/*
> 14
> 12
> 10
> 9
> 12
> 9
> 9
> 10
> 14
> 14
> 20
> 19
> 47
> 7
> 18
> 10
> 30
> 5
> 10
> 6
> 12
> 7
> 22
> 10
> 8
> 10
> 12
> 39
> 16
> 9
> 10
> 13
> 3
> 119
> 12
> 8
> 6
> 6
> 46
> 16
> 6
> 14
> 10
> 32
> 26
> 10
> 128
> 10
> 25
> 15
> 47
> 4
> 74
> 22
> 27
> 11
> 48
> 48
> 26
> 10
> 8
> 13
> 3
> 3
> 29
> 7
> 10
> 10
> 10
> 39
> 9
> 10
> 39
> 13
> 10
> 9
> 9
> 17
> 68
> 88
> 9
> 54
> 17
> 24
> 28
> 10
> 11
> 1
> 7
> 13
> 14
> 6
> 89
> 9
> 21
> 23
> 18
> 9
> 2
> 119

*/
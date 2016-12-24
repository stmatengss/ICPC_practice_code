#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int N=2504;
int c,l;
struct cow{
	int min;
	int max;
};
struct bottle{
	int spf;
	int cover;
};
cow a[N];
bottle b[N];
priority_queue<int, vector<int> ,greater<int> >pq;

int cmp1(cow a,cow b)
{
	return a.min<b.min;
}

int cmp2(bottle a,bottle b)
{
	return a.spf<b.spf;
}

int main()
{
	int i,j;
	int sum=0;
	int temp;
	cin>>c>>l;
	for(i=0;i<c;i++)cin>>a[i].min>>a[i].max;
	for(i=0;i<l;i++)cin>>b[i].spf>>b[i].cover;
	sort(a,a+c,cmp1);
	sort(b,b+l,cmp2);
	j=0;
	for(i=0;i<l;i++)
	{
		while(j<c&&b[i].spf>=a[j].min)
		{
			pq.push(a[j].max);
			j++;
		}
		while(!pq.empty()&&b[i].cover)
		{
			temp=pq.top();
			pq.pop();
			if(temp>=b[i].spf)
			{
				sum++;
				b[i].cover--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
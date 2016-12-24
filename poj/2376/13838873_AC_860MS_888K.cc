#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct cow{
	int begin;
	int end;
};
cow data[25004];
int cmp(cow a,cow b)
{
	if(a.begin!=b.begin)return a.begin<b.begin;
	return a.end>b.end;
}

int main()
{
	int i=0,j,k;
	int n,goal;
	int next=0;
	int counter=0;
	int maxend;
	int maxpos;
	cin>>n>>goal;
	for(i=0;i<n;i++)
	{
		cin>>data[i].begin>>data[i].end;
	}
	sort(data,data+n,cmp);
	i=0;
	if(data[i].begin!=1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	//next=data[i].end;
	while(i<n)
	{
		j=i+1;
		maxend=data[i].end;
		maxpos=j;
		while(data[j].begin<=data[i].end+1&&j<n)
		{
			if(data[j].end>maxend)
			{
				maxend=data[j].end;
				maxpos=j;
			}
			j++;
		}
		if(maxend==data[i].end)break;
		i=maxpos;
		counter++;
	}
	if(maxend>=goal)cout<<counter+1<<endl;
	else cout<<"-1"<<endl;
	return 0; 
}
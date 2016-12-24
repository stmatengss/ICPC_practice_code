#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct time{
	int no;
	int begin;
	int end;
	int worker;
	friend bool operator< (time a,time b)
	{
		return a.end>b.end;
	}
};
int now;
int sum;
time data[50004];
int temp;
int note[50004];
priority_queue<time>q;

int cmp(time a,time b)
{
	return a.begin<b.begin;
}

int main()
{
	int i,j;
	int n;
	int begin,end;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>begin>>end;
		data[i].begin=begin;
		data[i].end=end;
		data[i].no=i;
	}
	sort(data,data+n,cmp);
	sum=1;
	//now=0;
	data[0].worker=1;
	q.push(data[0]);
	note[0]=1;
	for(i=1;i<n;i++)
	{
		temp=data[i].begin;
		//if(q.empty())
		if(!q.empty()&&q.top().end<temp)
		{
			temp=q.top().worker;
			q.pop();
			//now++;
			note[data[i].no]=temp;
			data[i].worker=temp;
			//if(q.empty())break;	
		}
		else
		{
			sum++;
			note[data[i].no]=sum;
			data[i].worker=sum;	
		}
		q.push(data[i]);
	}
	cout<<sum<<endl;
	for(i=0;i<n;i++)cout<<note[i]<<endl;
	return 0;
}
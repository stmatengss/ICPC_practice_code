#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int N=10000;
int state[N]={0};
int primer[N]={0};
queue<pair<int,int> >q;

void prim_find()
{
	int i,j;
	for(i=2;i<N;i++)
	{
		if(primer[i]==0)
		{
			for(j=2*i;j<N;j=j+i)
				primer[j]=1;
		}
	}
} 

int bfs(int a,int b)
{
	while(!q.empty())q.pop();
	q.push(make_pair(a,0) );
	int counter,num,temp,i;
	state[a]=1;
	while(!q.empty())
	{
		num=q.front().first;
		counter=q.front().second;
		if(num==b)return counter;
		/*****/
		temp=num-num%10;
		for(i=0;i<=9;i++)
		{
			if(primer[temp]==0&&state[temp]==0)
			{
			 	q.push(make_pair(temp,counter+1) );
			 	state[temp]=1;
			}
			temp=temp+1;
		}
		temp=num-(num%100-num%10);
		for(i=0;i<=9;i++)
		{
			if(primer[temp]==0&&state[temp]==0)
			{
			 	q.push(make_pair(temp,counter+1) );
			 	state[temp]=1;			 	
			}
			temp=temp+10;
		}
		temp=num-(num%1000-num%100);
		for(i=0;i<=9;i++)
		{
			if(primer[temp]==0&&state[temp]==0)
			{
			 	q.push(make_pair(temp,counter+1) );
			 	state[temp]=1;
			}
			temp=temp+100;
		}
		temp=temp%1000;
		for(i=0;i<=9;i++)
		{
			if(primer[temp]==0&&state[temp]==0)
			{
			 	q.push(make_pair(temp,counter+1) );
			 	state[temp]=1;
			}
			temp=temp+1000;
		}
		q.pop();
	}	
}

int main()
{
	int a,b,n;
	int i;
	cin>>n;
	prim_find();
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<bfs(a,b)<<endl;
		memset(state,0,sizeof(state));
	} 	
	return 0;
}
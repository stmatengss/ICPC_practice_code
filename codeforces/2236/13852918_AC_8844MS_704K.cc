#include<iostream>
#include<cstdio>
#define B(x) x*x
using namespace std;

const int N=1004;
struct point{
	int x;
	int y;
};
point po[N];
int n,d;
int father[N];
int rank[N]={0};
int state[N]={0};

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		//rank[i]=0;
	}
}

int find(int x)
{
	return father[x]==x?x:find(father[x]);
}

void unin(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank[x]>rank[y])
	{
		father[y]=x;
	}
	else
	{
		father[x]=y;
		if(rank[x]=rank[y])rank[x]++;
	}
	return;
}

bool same(int x,int y)
{
	return find(x)==find(y);
}

int main()
{
	cin>>n>>d;
	char temp;
	int temp1,temp2,i;
	double x,y;
	double D=d*d;
	//int counter=n;
	init(n);
	for(i=1;i<=n;i++)cin>>po[i].x>>po[i].y;
	while(cin>>temp)
	{
		if(temp=='O')
		{
			cin>>temp1;
			x=po[temp1].x;
			y=po[temp1].y;
			for(i=1;i<=n;i++)
			{
				if(state[i]&&((x-po[i].x)*(x-po[i].x)+(y-po[i].y)*(y-po[i].y)<=D))unin(temp1,i);
			}
			state[temp1]=1;	
		}
		else
		{
			cin>>temp1>>temp2;
			if(same(temp1,temp2))cout<<"SUCCESS"<<endl;
			else cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
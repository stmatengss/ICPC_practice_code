#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
	int from,to,value;
};
edge e[20004];
int father[1004],rank[1004];
int n,m;


int cmp(const edge a,const edge b)
{
	return a.value>b.value;
}

int init()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
		rank[i]=0;
	}	
}

int find(int x)
{
	if(father[x]==x)return x;
	else return find(father[x]);
}

void unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(rank[x]>rank[y])
	{
		father[y]=x;
	}
	else
	{
		father[x]=y;
		if(rank[x]==rank[y])rank[x]++;
	}
}

int main()
{
	int i,j;
	int counter=0;
	int from,to,value;
	long long sum=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>from>>to>>value;
		e[i].from=from;
		e[i].to=to;
		e[i].value=value;
	}
	sort(e+1,e+m+1,cmp);
	init();
	for(i=1;i<=m;i++)
	{
		if(find(e[i].from)!=find(e[i].to))
		{
			unit(e[i].from,e[i].to);
			sum+=e[i].value;
			counter++;
		}
		if(counter==n-1)
		{
			cout<<sum<<endl;
			return 0;
		}	
	}
	cout<<"-1"<<endl;
	return 0;
}
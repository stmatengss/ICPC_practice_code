#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct edge{
	int x,y;
	double v;
	edge(int x,int y,double v):x(x),y(y),v(v){
	}
};

int s,n;
int father[504],rank[504];
double pointx[504],pointy[504];
vector<edge>e;
int counter;

void init()
{
	int i;
	e.clear();
	for(i=1;i<=n;i++)
		father[i]=i,rank[i]=0;
}

int getfather(int x)
{
	if(x==father[x])
		return x;
	return getfather(father[x]);
}

bool unin(int x,int y)
{
	x=getfather(x),y=getfather(y);
	if(x==y)
		return false;
	else
	{
		if(rank[x]>rank[y])
		{
			father[y]=x;
		}
		else
		{
			father[x]=y;
			if(rank[x]==rank[y])rank[x]++;
		}
		return true;
	}
}

double dis(int x,int y)
{
	return sqrt((pointx[x]-pointx[y])*(pointx[x]-pointx[y])
			+(pointy[x]-pointy[y])*(pointy[x]-pointy[y]));
}

int cmp(edge x,edge y)
{
	return x.v<y.v;
}

int main()
{
	int i,j;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s>>n;
		init();
		counter=0;
		for(i=1;i<=n;i++)
			cin>>pointx[i]>>pointy[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				e.push_back(edge(i,j,dis(i,j)));
			}
		sort(e.begin(),e.end(),cmp);
		for(i=0;i<e.size();i++)
		{
			if(unin(e[i].x,e[i].y))
				counter++;
			if(counter==n-s)
				break;
		}
		printf("%.2lf\n",e[i].v);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int v;
int x,y;
long long res=0;
struct edge{
	int x,y,v;
	edge(int x,int y,int v):x(x),y(y),v(v){
		
	}
	
};
vector<edge>e;
int father[10004];

bool operator<(const edge &a,const edge &b)
{
	return a.v<b.v;
}

int cmp(edge a,edge b)
{
	return a.v<b.v;
}

void init()
{
	int i;
	for(i=1;i<=n;i++)
		father[i]=i;
}

int getfather(int x)
{
	if(father[x]==x)return x;
	return getfather(father[x]);
}

//int unin(int x,int y)
//{
//	x=getfather(x);
//	y=getfather(y);
//	x=father[y];
//}

int main()
{
	int i,j;
	while(cin>>n)
	{
	e.clear();
	res=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>v;
			if(v!=0)
			{
				e.push_back(edge(i,j,v));
			}
		}
	init();
	int counter=0;
	sort(e.begin(),e.end());
	for(i=0;i<=e.size();i++)
	{
		x=getfather(e[i].x);
		y=getfather(e[i].y);
		if(x!=y)
		{
			father[x]=y;
			res+=e[i].v;
			counter++;
		}
		if(counter==n-1)
			break;
	}
	cout<<res<<endl;
	}
	return 0;
}
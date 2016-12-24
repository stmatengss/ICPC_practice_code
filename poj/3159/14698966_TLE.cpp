#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;
const ll inf=1LL<<60;
ll d[30001];
struct edge{
	int to;
	ll cost;
	edge(int to,ll cost):to(to),cost(cost){
	}
};
typedef pair<ll,int> p;
vector<edge>g[30001];
int n,m;

int dijkstra()
{
	priority_queue<p,vector<p>,greater<p> >pq;
	fill(d,d+n+1,inf);
	d[1]=0;
	pq.push(p(0,1));
	p tmp;
	int v;
	while(!pq.empty())
	{
		tmp=pq.top();
		pq.pop();
		v=tmp.second;
		if(tmp.first<=d[v])
		{
			for(int i=0;i<g[v].size();i++)
			{
				edge e=g[v][i];
				if(d[e.to]>d[v]+e.cost)
				{
					d[e.to]=d[v]+e.cost;
					pq.push(p(d[e.to],e.to));
				}
			}
		}
	}
	cout<<d[n]<<endl;
}

int main()
{
	int i,j,k;
	int from,to;
	ll cost;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>from>>to>>cost;
		g[from].push_back(edge(to,cost));
	}
	dijkstra();
	return 0;
}
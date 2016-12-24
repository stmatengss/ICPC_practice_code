#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;
const ll inf=1LL<<60;
ll d[30004];
struct edge{
	int to;
	int next;
	ll cost;
	edge(){
	}
};

edge g[150004];
edge e;
typedef pair<ll,int> p;
int n,m;
int cnt=0;
int head[30004];

void addedge(int from,int to,ll cost)
{
	g[cnt].to=to;
	g[cnt].cost=cost;
	g[cnt].next=head[from];
	head[from]=cnt++;
}

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
			for(int i=head[v];i!=-1;i=g[i].next)
			{
				e=g[i];
				if(d[e.to]>d[v]+e.cost)
				{
					d[e.to]=d[v]+e.cost;
					pq.push(p(d[e.to],e.to));
				}
			}
		}
	}
//	cout<<d[n]<<endl;
	printf("%I64d\n",d[n]);
}

int main()
{
	int i,j,k;
	int from,to;
	ll cost;
//	cin>>n>>m;
//	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	fill(head,head+n+1,-1);
	for(i=1;i<=m;i++)
	{
//		cin>>from>>to>>cost;
		scanf("%d%d%I64d",&from,&to,&cost);
		addedge(from,to,cost);
	}
	dijkstra();
	return 0;
}
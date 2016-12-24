#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 1<<30
using namespace std;
int dis[1004][1004]={0};
int dis1[1004][1004]={0};
typedef pair<int,int> T;
int d[1004];
int d1[1004];
int n,x,m;

void dijkstra()
{
	int i,j;
	T now;
	fill(d,d+n+1,INF);
	priority_queue<T,vector<T>,greater<T> >pq;
	d[x]=0;
	pq.push(T(0,x));
	while(!pq.empty())
	{
		now=pq.top(),pq.pop();
		if(d[now.second]<now.first)continue;
		for(j=1;j<=n;j++)
		{
			if(dis[now.second][j]!=0&&d[j]>d[now.second]+dis[now.second][j])
			{
				d[j]=d[now.second]+dis[now.second][j];
				pq.push(T(d[j],j));
			}
		}
	}
	
	fill(d1,d1+n+1,INF);
	//priority_queue<T,vector<T>,greater<T> >pq;
	d1[x]=0;
	pq.push(T(0,x));
	while(!pq.empty())
	{
		now=pq.top(),pq.pop();
		if(d1[now.second]<now.first)continue;
		for(j=1;j<=n;j++)
		{
			if(dis1[now.second][j]!=0&&d1[j]>d1[now.second]+dis1[now.second][j])
			{
				d1[j]=d1[now.second]+dis1[now.second][j];
				pq.push(T(d1[j],j));
			}
		}
	}
//	cout<<pq.top()<<endl;
	int max=0;
	for(i=1;i<=n;i++)
	{
		if(i!=x&&d[i]+d1[i]>max)max=d[i]+d1[i];
	}
	cout<<max<<endl;
}

int main()
{
	cin>>n>>m>>x;
	int from,to,value;
	for(int i=0;i<m;i++)
	{
		cin>>from>>to>>value;
		dis[from][to]=value;
		dis1[to][from]=value;
	}
	dijkstra();
	return 0;
}
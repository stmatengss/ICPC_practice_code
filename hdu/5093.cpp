////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: stmatengss
////Nickname: Stmatengss
////Run ID: 
////Submit time: 2015-08-28 10:11:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:2092KB
//////////////////System Comment End//////////////////
#include<stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int INF = 1 << 29;
const int MAXN = 20000, MAXM = 500000;
struct edge
{
	int v, f, nxt;
};

int n, src, sink;
int g[MAXN + 10];
edge e[MAXM * 2 + 10];
int nume;

void addedge(int u, int v, int c)
{
	e[++nume].v = v;
	e[nume].f = c;
	e[nume].nxt = g[u];
	g[u] = nume;
	e[++nume].v = u;
	e[nume].f = 0;
	e[nume].nxt = g[v];
	g[v] = nume;
}
void init()
{
	memset(g, 0, sizeof(g));
	nume = 1;
}
queue<int> que;
bool vis[MAXN + 10];
int dist[MAXN + 10];
void bfs()
{
	memset(dist, 0, sizeof(dist));
	while (!que.empty())
		que.pop();
	vis[src] = 1;
	que.push(src);
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = g[u]; i; i = e[i].nxt)
		{
			if (e[i].f && !vis[e[i].v])
			{
				que.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = true;
			}
		}
	}
}
int dfs(int u, int delta)
{
	if (u == sink)
	{
		return delta;
	}
	else
	{
		int ret = 0;
		for (int i = g[u]; delta && i; i = e[i].nxt)
		{
			if (e[i].f && dist[e[i].v] == dist[u] + 1)
			{
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i ^ 1].f += dd;
				delta -= dd;
				ret += dd;
			}
		}
		return ret;
	}
}
int maxflow()
{
	int ret = 0;
	while (true)
	{
		memset(vis, 0, sizeof(vis));
		bfs();
		if (!vis[sink])
			return ret;
		ret += dfs(src, INF);
	}
}
int R_OFFSET = 2;
int C_OFFSET = 2502;
int OFFSET = 5004;
int raw_graph[60][60];
int value[60][60];

int main()
{
	int n_case;
	src=0;
	sink=1;

	scanf("%d", &n_case);
	for (int i = 0; i < n_case; i++)
	{
		int r_size, c_size;
		scanf("%d%d", &r_size, &c_size);
		init();
		char buff[1000];
		for (int i = 0; i < r_size; i++)
		{
			scanf("%s", buff);
			for (int j = 0; j < c_size; j++)
			{
				if (buff[j] == 'o')
					raw_graph[i][j] = 0;
				if (buff[j] == '*')
					raw_graph[i][j] = 1;
				if (buff[j] == '#')
					raw_graph[i][j] = 2;
			}
		}
		int r_cnt = R_OFFSET;
		int c_cnt = C_OFFSET;
		int point_cnt = OFFSET;
		for (int i = 0; i < r_size; i++)
		{
			r_cnt++;
			addedge(src, r_cnt, 1);

			for (int j = 0; j < c_size; j++)
			{
				point_cnt++;
				value[i][j]=point_cnt;
				if (raw_graph[i][j] == 1)
				{
					addedge(r_cnt, point_cnt, 1);
				}
				if (raw_graph[i][j] == 2)
				{
					r_cnt++;
					addedge(src, r_cnt, 1);
				}
			}
		}
		for (int i = 0; i < c_size; i++)
		{
			c_cnt++;
			addedge(c_cnt, sink, 1);
			for (int j = 0; j < r_size; j++)
			{
				point_cnt=value[j][i];
				if (raw_graph[j][i] == 1)
				{
					addedge(point_cnt,c_cnt, 1);
				}
				if (raw_graph[j][i] == 2)
				{
					c_cnt++;
					addedge(c_cnt,sink ,1);
				}
			}
		}
		int res=maxflow();
		printf("%d\n",res);

	}
}
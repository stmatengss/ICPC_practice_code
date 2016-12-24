#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[2004];
int color[2004]={0};
int n,m;

bool find(int x,int c)
{
	int i;
	color[x]=c;
	for(i=0;i<g[x].size();i++)
	{
		if(color[g[x][i]]==c)return false;
		if(color[g[x][i]]==0&&!find(g[x][i],-c))return false;	
	}
	return true;
}

int main()
{
	int t;
	int i,j;
	int from,to;
	cin>>t;
	int ST=0;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			g[i].clear();
		}
		fill(color,color+n+1,0);
		ST=1;
		for(i=1;i<=m;i++)
		{
			cin>>from>>to;
			g[from].push_back(to);
		}
		for(i=1;i<=n;i++)
		{
			if(color[i]==0)
			{
				if(!find(i,1))
				{
					cout<<"Suspicious bugs found!"<<endl;
					ST=0;
					break;
				}
			}
		}
		if(ST)cout<<"No suspicious bugs found!"<<endl;
	}
	return 0;
}
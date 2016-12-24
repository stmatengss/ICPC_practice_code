#include<iostream>
#include<algorithm>
#define INF -100000000
using namespace std;

int dis[1004][1004];
int maxcost[1004];
bool used[1004];
int n,m;

int main()
{
	int i,j;
	int counter=0;
	int from,to,value;
	long long sum=0;
	int now,nowmax;
	cin>>n>>m;
	for(i=1;i<=m;i++)
		{
			cin>>from>>to>>value;
			dis[from][to]=value;
			dis[to][from]=value;
		}
	fill(maxcost,maxcost+n+1,INF);
	fill(used,used+n+1,false);
	maxcost[1]=0;
	
	while(true)
	{
		now=-1;
		nowmax=INF;
		for(i=1;i<=n;i++)
		{
			if(!used[i]&&nowmax<maxcost[i])
			{
				now=i;
				nowmax=maxcost[i];
			}
		}
		if(now==-1)break;

		used[now]=true;
		sum+=nowmax;
		for(i=1;i<=n;i++)
		{
			maxcost[i]=max(maxcost[i],dis[now][i]);
		}
	}
	cout<<sum<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;
map<pair<int,int>,int>mp;
map<pair<int,int> ,int>::iterator it;
int x[1004],y[1004];
struct point{
	int x;
	int y;
};
ll res=0;
point po[1000004];

int cmp(const point a,const point b)
{
	if(a.y==b.y) return a.x<b.x;
	else
		return a.y<b.y;
}

int main()
{
	int i,j,k;
	int t,n;
	int e;
	scanf("%d",&t);
	while(t--)
	{
		res=0;
		mp.clear();
//		cin>>n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		int counter=0;
		e=(n-1)*n/2;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				po[counter].x=x[i]+x[j];
				po[counter].y=y[i]+y[j];
				counter++;
//				mp[make_pair(x[i]+x[j],y[i]+y[j])]++;
			}
		}
		sort(po,po+e,cmp);
		po[e].x=k;
		po[e].y=k;
		counter=0;
		int st=0;
		for(i=1;i<=e;i++)
		{
			if(po[i].x==po[i-1].x&&po[i].y==po[i-1].y)
			{
				counter++;
				st=1;
			}
			else
			{
				if(st==1)
				{
					res+=(counter)*(counter+1)/2;
					st=0;
				}
				counter=0;
			}
		}
//		for(it=mp.begin();it!=mp.end();++it)
//		{
////			cout<<(it->first/k)<<' '<<(it->first%k)<<' '<<(it->second)<<endl;
////			cout<<(it->second)<<endl;
//			res+=(1LL*it->second*(it->second-1)/2);
//		}
//		cout<<res<<endl;
		printf("%I64d\n",res);
	}
	return 0;
}